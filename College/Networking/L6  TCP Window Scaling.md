
Currently the flow control mechanism ensures that the TCP sender does not fill up the buffers at the TCP receivers
This is done by advertising rwnd (a 16 bit field)

But the **limitation** is that only a max of 2^16 = 65536 bytes can be advertised ( 64Kb ) can be advertised which is less.

### Solution
##### Window Scaling



