***********************
Sound Abstraction Layer
***********************

Here you will find a full description of the sound abstraction layer.

This abstraction layer takes care of everything related to sound like the playback of audio (WAV, MP3, AAC, Stream etc.).
This API is based on the `AudioI2S <https://github.com/schreibfaul1/ESP32-audioI2S>`_ library by `Schreibfaul <https://github.com/schreibfaul1>`_.

.. warning::

    The ``AudioI2S`` currently does not have a stable version.

API Reference
=============

.. doxygenclass::   Xila_Class::Sound_Class
    :members: