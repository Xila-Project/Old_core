# `Queue_Type`

# Description

`Queue_Type` is a thread safe FIFO (First In First Out) buffer. It can be used to send messages between tasks, softwares / modules. As it is a FIFO buffer, data is sent to the back of the queue, and data is received from the front of the queue, but data can also be sent to the front of the queue.

# API reference

```{eval-rst}

.. doxygenclass:: Xila_Namespace::Queue_Class
    :members:

```