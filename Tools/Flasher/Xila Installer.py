import os
import subprocess
import time
import shutil

Current_Path = os.path.dirname(__file__)
os.chdir(Current_Path)

os.system('cls')
print('||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||')
print('||               __________   __   __  _____   _                              ||')
print('||              |      |   |  \ \ / / |_   _| | |          /\                 ||')
print('||              |______|   |   \ V /    | |   | |         /  \                ||')
print('||              |   |__|___|    | |     | |   | |        / /\ \               ||')
print('||              |   |      |   / . \   _| |_  | |____   / ____ \              ||')
print('||              |___|______|  /_/ \_\ |_____| |______| /_/    \_\             ||')
print('||                                                                            ||')
print('||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||')
print('||                                                                            ||')
print('||                              Xila Installer                                ||')
print('||            Version : 0.1.0 - Alix ANNERAUD - MIT Licence - 2021            ||')
print('||                                                                            ||')
print('||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||')
print('||                                                                            ||')
input('|| > Press Enter to continue ...                                              ||')
print('|| > Starting flashing tool ...                                               ||')
print('||                                                                            ||')


Create_Drive = input('|| > Do you want to create a new installation drive ? (Y/N) ')
if Create_Drive=='Y':
    print('|| > Please insert the empty drive to initialize.                             ||')
    Destination_Path = input('|| > Enter the drive letter :')
    Destination_Path = Destination_Path + ":\\"
    shutil.copytree('./Drive', Destination_Path)

print('||                                                                            ||')
Create_Drive = input('|| > Do you to write Xila to an ESP32 ? (Y/N) ')
if Create_Drive=='Y':
    os.chdir('./Executables')
    print('||                                                                            ||')
    print('|| > Please close all serial monitors in order to not distrub opeations.      ||')
    time.sleep(2)
    Install = subprocess.run('pip install setuptools', stdout=subprocess.DEVNULL)
    if Install.returncode == 0:
        print('|| > Succed to install setuptools                                             ||')
    else:
        print('|| > Failed to install setuptools                                             ||')
        exit()
    time.sleep(2)
    Install = subprocess.run('pip install esptool', stdout=subprocess.DEVNULL)
    if Install.returncode == 0:
        print('|| > Succed to install esptool                                                ||')
    else:
        print('|| > Failed to install esptool                                                ||')
        exit()
    time.sleep(2)
    print('|| > Start esptool ...                                                        ||')
    print('||                                                                            ||')
    print('||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||')
    time.sleep(2)
    Flash = os.system('esptool.py write_flash --flash_size 4MB 0x1000 bootloader.bin 0x8000 partitions.bin 0x10000 firmware.bin')
    print('||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||')
    print('||                                                                            ||')
    if Flash == 0:
        print('|| > Succed to flash Xila                                                     ||')
    else:
        print('|| > Failed to flash Xila                                                     ||')
    time.sleep(2)

print('||                                                                            ||')
print('|| > Press Enter to close utility ...                                         ||')
print('||                                                                            ||')
input('||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||')
exit()

