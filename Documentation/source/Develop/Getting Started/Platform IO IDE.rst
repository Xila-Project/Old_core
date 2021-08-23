***************************************************
Getting Started With Development On Platform IO IDE
***************************************************

Here you will find instructions on how to setup the Platform IO IDE for development purpose.

Requirements
============

You will need the following parts in order to start develop third party software :

* A ``computer``.
* The latest version of `Platform IO IDE <https://platformio.org/platformio-ide>`_.
* The latest version of the `Nextion editor <https://nextion.tech/nextion-editor/>`_.

Instructions
============

Firstly, create a new project in **Platform IO**.

Then, add the following line to the ``platformio.ini`` file.

.. code-block::

    lib_deps = alix-anneraud/Xila   ;import Xila as a library.

You can test your installation with the following sketch :

.. code-block:: c

    #include "Xila.hpp"

    void setup()
    {
        Xila.System.Start();
    }

    void loop()
    {
        Xila.Task.Delete();
    }

When you launch the compilation or the download of the software, **Platform IO** will take care of installing **Xila** as well as all its dependencies.

You are now ready to start developing software for **Xila**.
Consult :ref:`software reference` in order to have more details on the functioning of **Xila**.