# 📜 Registries

Here you will find how Xila stores its configuration.

## Overview

Xila use registries to store its configuration. It is a way to store data in a file. These registries have the ``.xrf`` extension and are contained in the ``/Xila/Registry`` folder. Thanks to JavaScript Object Notation (J.S.O.N.), these registries are quite easy to apprehend by hand.

During startup, Xila checks and loads its various registers. If a registry is corrupted, it will automatically reset with default values. If the registry is not corrupted, but the data in the registry is incorrect, you can still delete it. Xila will regenerate it automatically.

Here you will find how to configure Xila in depth so that it can adapt to all your needs.

Xila use registries to store its configuration.
These registries have the ``.xrf`` extension and are contained in the ``/Xila/Registry`` folder.
Thanks to JavaScript Object Notation (J.S.O.N.), these registries are quite easy to apprehend.

During startup, Xila checks and loads its various registers.
If a registry is corrupted, it will automatically reset with default values.
If the registry is not corrupted, but the data in the registry is incorrect, you can still delete it.
Xila will regenerate it automatically.

Each registry begin with a ``Registry`` key.
It allows you to know if the loaded register is indeed the one targeted.

:::{warning}
    Be careful with the ``System.xrf`` registry. Because this one cannot be repaired.
    If a corruption occur, it is then necessary to manually replace the latter with a healthy file (can be found in install archive).
:::

## Registries Reference


### Display

```
.. csv-table::
    :header-rows:   1
    :file:          Registries/Display.csv
```

### Keyboard

.. csv-table::
    :header-rows:   1
    :file:          Registries/Keyboard.csv

### Network

.. csv-table::
    :header-rows:   1
    :file:          Registries/Network.csv

### Power

.. csv-table::
    :header-rows:   1
    :file:          Registries/Power.csv

### Sound

.. csv-table::
    :header-rows:   1
    :file:          Registries/Sound.csv

### System

.. csv-table::
    :header-rows:   1
    :file:          Registries/System.csv



