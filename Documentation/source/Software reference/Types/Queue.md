# `Queue_Type`

## Overview

`Queue_Type` is a thread safe FIFO (First In First Out) buffer. It can be used to send messages between tasks, softwares / modules. As it is a FIFO buffer, data is sent to the back of the queue, and data is meant to be received from the front of the queue. But you can also send to the front and receive from the back (must be used reasonably since it consumes more CPU cycles).

:::{note}
    `Queue_Type` is an alias of `Queue_Class` (used by the internals).
:::

## API reference

```{eval-rst}

.. doxygenclass:: Xila_Namespace::Queue_Class
    :members:

```