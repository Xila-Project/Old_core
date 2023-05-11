import socket
import time
from watchdog.observers import Observer
from watchdog.events import FileSystemEventHandler
import os

HOST = '192.168.0.175'  # Adresse IP du serveur
PORT = 80  # Port sur lequel le serveur écoute
FILE_PATH = os.path.join(os.path.dirname(__file__), 'REPL.cpp')  # Chemin du fichier à envoyer

class FileModifiedHandler(FileSystemEventHandler):
    def on_modified(self, event):
        print(f'Fichier modifié : {event.src_path}')
        send_file()

def send_file():
    with open(FILE_PATH, 'rb') as file:
        # Créer une connexion avec le serveur
        with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
            s.connect((HOST, PORT))
            print('Connecté au serveur')

            # Envoyer les données du fichier au serveur
            while True:
                data = file.read(256)  # Lire les données par blocs de 1024 octets
                if not data:
                    break
                s.sendall(data)

            print('Fichier envoyé')

if __name__ == '__main__':
    event_handler = FileModifiedHandler()
    observer = Observer()
    observer.schedule(event_handler, FILE_PATH, recursive=False)
    observer.start()
    print(f'Observation du fichier {FILE_PATH} en cours...')
    
    try:
        while True:
            time.sleep(1)
    except KeyboardInterrupt:
        observer.stop()
    
    observer.join()