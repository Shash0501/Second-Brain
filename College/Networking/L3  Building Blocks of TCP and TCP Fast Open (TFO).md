
## TCP
- TCP is called a **connection oriented protocol** because it requires a logical connection to be established before data can be exchanged
- **(Bi-Directional)** TCP connection provides a full-duplex service i.e. data can be transmitted in both directions simultaneously. 
- **Reliable** as the delivery of data is confirmed by ACK
	- Lost data is retransmitted if the ACK does not arrive within a time interval
- **Order Maintained** : Data is delivered in order and TCP does this by a process called segmentation. 
	- It divides the data to be sent into smaller pieces called segment. Every segment has a sequence number and the sender resends a segment if it hasn't received the ACK for that particular segment
	- [[Questions#Data is delivered ‘in-order’ (how is this achieved?) L3S2| How data delivered in order]]

#### Flow Control
TCP sender ensures that it does not cause a buffer overflow at the TCP receiver
[[Questions#TCP sender ensures that it does not cause a buffer overflow at the TCP receiver (how is this achieved?) L3S2|How is it done?]]
#### Error Control
It has a checksum field for error control.
[[Questions#Data link layer provides Error detection and Error corrections techniques. So why is error control needed at the transport layer?| Why is it needed at transport layer too?]]

#### Congestion Control
- Congestion control is necessary so that TCP sender does not cause buffer overflow at the 'router' or any other 'intermediate device'
- Some of the latest congestion control algorithms are: BBR and Prague

### TCP header

![[Pasted image 20230829124417.png]]

The maximum amount of data that can be grabbed and placed in a segment is limited by the maximum segment size (MSS). The 

in context of TCP a word is a 32 bit unit of data or 4 bytes

**Source Port** (16 bit): 
- Holds the port address of the application that is sending the data

**Destination Port** (16 bit) : 
- Holds the port address of the application that is receiving the data

**Sequence number** (32 bit): 
- The byte number of the first byte is sent in that particular segment. 
- It is then used to reassemble the message at the receiving end of the segments that are received out of order

**Acknowledgement Number** (32 bit) : 
- The byte number that the receiver expects to receive next.

**Data offset / HLEN ( Header Length )** ( 4 bit ) : 
- It is a 4-bit field that indicates the length of the TCP header. 
- The minimum length of the HLEN is 5 which tells that the TCP header size is 5 x 4 = 20 bytes.
- The max value of the HLEN is 15 when the size of the header is 60 (15 x 4).
- ***This is used by the receiver to determine where the data portion of the TCP segment starts***

**Control Flags**
- These are 6 1-bit control bits that control connection establishment, connection termination, connection abortion, flow control, mode of transfer
- **SYN**(Synchronization) 
	- This flag is used to initiate a connection.
	- The sender sets SYN = 1 in the first packet
	- The receiver responds with a packet that also has the SYN = 1.
- **ACK**
	- This is used to acknowledge the receipt of the data.
- **FIN**
	- It is used to terminate a connection.
	- The sender sets the FIN = 1 in the last packet of the connection
	- The receiver responds with a packet that has the FIN = 1 which terminates the connection between the two hosts
- **URG**
	- This flag is used to indicate that the data in the packet is urgent. 
	- The sender sets the URG flag in a packet to indicate that the data in the packet should be **processed** **immediately** by the **receiver**
	- Receiver forwards urgent data to the receiving application on a separate channel.
- **PSH**
	- The sender sets the PSH flag in a packet to tell the receiver to process the data in the packet immediately without buffering it.
	- Unlike URG bit, PSH does not prioritize the data
	- It just causes all the segments in the buffer to be pushed immediately to the receiving application.
	- The same order is maintained in which the segments arrived
	- It is not a good practice to set PSH bit = 1.
	- This is because it disrupts the working of receiver’s CPU and forces it to take an action immediately.
- **RST**
	- This is used to reset a connection. *?? more info*
	- It flushes all the connections and reallocate the resources for the connections
	- This is done if there is some issue in the connection

**Window Size**
The window size in the TCP header is a 16-bit field that specifies the **number of bytes that the sender can send before** **it has to wait for an acknowledgment** from the receiver. The window size is used to control the flow of data between the sender and receiver.
 
**Checksum**
This field holds the checksum for error control. It is mandatory in TCP as opposed to UDP.

**Urgent Pointer**
- Urgent pointer is a 16 bit field.
- It indicates how much data in the current segment counting from the first data byte is urgent.
- Urgent pointer added to the sequence number indicates the end of urgent data byte.

#### **Options**
- Options field is used for several purposes.
- The size of options field vary from 0 bytes to 40 bytes.
- Options field is generally used for the following purposes-
	1. Time stamp
	2. Window size extension
	3. Parameter negotiation
	4. Padding

###### Window Size Extension
- It is a TCP option that allows the sender and receiver to negotiate a larger window size
- The window size extension option is a 3-byte option.
- The first byte is the option code, which is 3.
- The second byte is the window scale factor, which is a number from 0 to 14.
- The third byte is padding, which is always 0.
- The window size extension option is negotiated during the TCP three-way handshake. The sender sends the window size extension option in the SYN packet. The receiver can accept the window size extension option by setting the ACK flag in the SYN-ACK packet.


## TCP Handshake

![[Pasted image 20230829142450.png]]


### Can we avoid TCP handshake?

Problem
- One RTT is large amount of time for 'short lived' connection

Application Layer Solution
- Use persistent Connection feature of HTTP 1.1
	- Establishes a TCP connection only once for multiple HTTP requests to the same web server
- Common Lines in the HTTP header
	- Connection : Keep-Alive
	- Keep-Alive : Timeout = 5, max = 1000

##### TFO (TCP Fast open)
![[Pasted image 20230829143112.png]]
- Data can be piggybacked with the SYN or SYN-ACK request.
	
**Conditions for TFO**
- Must not be a new connection
	- It works only for repeat connections because of the requirement of cryptographic cookie
- Total amount of data piggybacked with the SYN packet must be within specified limits
- Only certain types of HTTP requests can be sent (GET)
![[Pasted image 20230829143407.png]]


The client and server let each other know that they support TFO (TCP Fast Open) using the TCP options field in the SYN packet. The TCP options field is a variable-length field that can be used to carry additional information that is not part of the standard TCP header.

The TFO option is a **4-byte** option. The first byte is the **option code**, which is **34**. The second byte is the length of the option, which is always 16 bytes. The third and fourth bytes are padding, which are always 0.

The TFO option contains a cookie that is generated by the client. The server can use the cookie to verify that the client supports TFO.

If the server supports TFO, it will respond with a SYN-ACK packet that includes the TFO option. The server will also generate its own cookie and include it in the TFO option.

If both the client and server support TFO, they will be able to use TFO to improve the performance of the connection.

Here are the steps on how the client and server let each other know that they support TFO:

1. The client sends a SYN packet with the TFO option.
2. The server responds with a SYN-ACK packet with the TFO option.
3. If both the client and server support TFO, they will be able to use TFO to improve the performance of the connection.

Here are some of the benefits of using TFO:

- It can reduce the number of round trips required to establish a connection.
- It can improve the performance of the connection by reducing the amount of data that needs to be sent.
- It can improve the reliability of the connection by reducing the risk of packet loss.