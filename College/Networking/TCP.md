TCP is called a connection oriented protocol because it requires a logical connection to be established before data can be exchanged

TCP connection provides a full-duplex service i.e data can be transmitted in both directions simultaneously. 

TCP is **reliable** as the delivery of data is confirmed by ACK;s
Lost data is retransmitted if the ACK does not arrive within a time interval
Data is delivered in order and TCP does this by a process called segmentation. It divides the data to be sent into smaller pieces called segment. Every segment has a sequence number and the sender resends a segment if it hasn't received the ACK for that particular segment

#### Flow Control
TCP sender ensures that it does not cause a buffer overflow at the TCP receiver
#### Error Control
It has a checksum field for error control
#### Congestion Control
Congestion control is necessary so that TCP sender deos not cause buffer overflow at the 'router' or any other 'intermediate device'

### TCP header

![[Pasted image 20230829124417.png]]

The maximum amount of data that can be grabbed and placed in a segment is limited by the maximum segment size (MSS). The 

in context of TCP a word is a 32 bit unit of data or 4 bytes

**Source Port** : 
- 16 bit field that holds the port address of the application that is sending the data

**Destination Port** : 
- 16 bit field that holds the port address of the application that is receiving the data

**Sequence number** : 
- The byte number number of the first byte is sent in that particular segment. 
- It is then used to reassemble the message at the receiving end of the segments that are received out of order

**Acknowledgement Number** : 
- The byte number that the receiver expects to receive next.

**Data offset / HLEN ( Header Length)** : 
- It is a 4-bit field that indicates the length of the TCP header. 
- The minimum length of the HLEN is 5 which tells that the TCP header size is 5 x 4 = 20 bytes.
- The max value of the HLEN is 15 when the size of the header is 60 (15 x 4).
- *This is used by the receiver to determine where the data portion of the TCP segment starts*

**Control Flags**
- These are 6 1-bit control bits that control connection establisment, connection termination, connection abortion, flow control, mode of transfer
- **SYN**(Synchronization) 
	- This flag is used to initiate a connection.
	- The sender sets SYN = 1 in the first packet
	- The receiver responds with a packet that also has the SYN = 1.
- **ACK**
	- This is used to acknowledge the receipt of the data.
- **FIN**
	- It is used to terminate a connection.
	- The sender sets the FIN = 1 in the last packet of the connection
	- The receiver responds with a packer that has the FIN = 1 which terminates the connection between the two hosts
- **URG**
	- This flag is used to indicate that the data in the packet is urgent. 
	- The sender sets the URG flag in a packet to indicate that the data in the packet should be processed immediately by the receiver
	- Receiver forwards urgent data to the receiving application on a separate channel.
- **PSH**
	- The sender sets the PSH flag in a packet to tell the receiver to process the data in the packer immediately without buffering it.
	- Unlike URG bit, PSH does not prioritize the data
	- It just causes all the segments in the buffer to be pushed immediately to the receiving application.
	- The same order is maintained in which the segments arrived
	- It is not a good practice to set PSH bit = 1.
	- This is because it disrupts the working of receiver’s CPU and forces it to take an action immediately.
- **RST**
	- This is used to rest a connection.

**Window Size**
The window size in the TCP header is a 16-bit field that specifies the number of bytes that the sender can send before it has to wait for an acknowledgment from the receiver. The window size is used to control the flow of data between the sender and receiver.

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
