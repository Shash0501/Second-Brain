L3S2
if the resources are available, how do the TCP endpoints know the ‘amount’ of resources available?


#### Data is delivered ‘in-order’ (how is this achieved?) L3S2

TCP ensures that data is delivered in order by using sequence numbers and acknowledgments (ACKs). Each TCP segment is assigned a sequence number, which is a unique identifier for that segment. When a receiver receives a segment, it sends an ACK back to the sender, indicating the next sequence number that it expects to receive.

If a sender does not receive an ACK for a segment within a certain amount of time, it will retransmit the segment. This ensures that all segments are delivered to the receiver, even if some segments are lost or delayed.

In addition to using sequence numbers, TCP also uses a buffer to store received segments in order. This ensures that the segments are delivered to the application in the order that they were sent.

Here is an example of how TCP ensures in-order delivery:

1. The sender sends a segment with sequence number 1.
2. The receiver receives the segment and sends an ACK with sequence number 2.
3. The sender sends a segment with sequence number 2.
4. The receiver receives the segment and sends an ACK with sequence number 3.
5. The sender sends a segment with sequence number 3.
6. The receiver loses the segment.
7. The sender does not receive an ACK for the segment and retransmits it.
8. The receiver receives the retransmitted segment and sends an ACK with sequence number 4.
9. The sender sends a segment with sequence number 4.
10. The receiver receives the segment and delivers it to the application.

The receiver will buffer the segment with sequence number 3 until it receives the segment with sequence number 2. Once the receiver has received all of the segments in order, it will deliver them to the application in order.

TCP's in-order delivery mechanism is essential for many applications, such as web browsers and email clients. Without in-order delivery, these applications would not be able to function properly.

#### TCP sender ensures that it does not cause a buffer overflow at the TCP receiver (how is this achieved?) L3S2
TCP sender ensures that it does not cause a buffer overflow at the TCP receiver by using a mechanism called **flow control**. Flow control is a way for the receiver to tell the sender how much data it is willing to receive. The sender uses this information to control how much data it sends.

Flow control is implemented using a window mechanism. The receiver maintains a window, which is a range of sequence numbers that it is willing to receive. The receiver sends the window size to the sender in the ACK packets. The sender uses the window size to control how much data it sends.

The sender will not send more data than the window size allows. If the sender has more data to send than the window size allows, it will wait for the receiver to send an ACK packet with a larger window size.

Here is an example of how TCP flow control works:

1. The receiver sends an ACK packet with a window size of 100 segments.
2. The sender has 200 segments to send.
3. The sender sends 100 segments.
4. The receiver receives the 100 segments and sends an ACK packet with a window size of 100 segments.
5. The sender has 100 segments to send.
6. The sender sends 100 segments.
7. The receiver receives the 100 segments and sends an ACK packet with a window size of 0 segments.
8. The sender has no more segments to send.

The sender will wait for the receiver to send an ACK packet with a larger window size before sending any more data.

TCP flow control is a very effective way to prevent buffer overflows at the TCP receiver. It is also a very efficient way to use the network bandwidth.

In addition to flow control, TCP also uses another mechanism to prevent buffer overflows at the receiver: **congestion control**. Congestion control is a way for TCP to reduce the amount of data it sends if the network is congested.

Congestion control is implemented using a number of different mechanisms, such as the TCP slow start algorithm and the TCP congestion window. These mechanisms work together to ensure that TCP does not send more data than the network can handle.

By using flow control and congestion control, TCP is able to ensure that it does not cause a buffer overflow at the TCP receiver.

#### Data link layer provides Error detection and Error corrections techniques. So why is error control needed at the transport layer?

Error control is needed at the transport layer for a number of reasons:

- **The data link layer may not be able to detect or correct all errors.** The data link layer typically uses checksums to detect errors. However, checksums can be fooled by certain types of errors, such as burst errors.
- **The data link layer may not be able to recover from all errors.** If the data link layer detects an error, it may simply drop the packet. This can lead to data loss.
- **The transport layer needs to provide reliable end-to-end delivery.** The transport layer needs to ensure that all data is delivered to the receiver in the correct order and without errors. This cannot be guaranteed by the data link layer alone.

The transport layer uses a number of techniques to provide reliable end-to-end delivery, including:

- **Sequence numbers:** The transport layer assigns a sequence number to each packet. This allows the receiver to detect and reorder packets that have been received out of order.
- **Acknowledgments:** The receiver sends acknowledgments (ACKs) back to the sender to indicate which packets have been received successfully. The sender can use the ACKs to retransmit packets that have been lost or corrupted.
- **Timeouts:** The sender uses timeouts to detect lost packets. If a sender does not receive an ACK for a packet within a certain amount of time, it retransmits the packet.

By using these techniques, the transport layer can provide reliable end-to-end delivery even if the data link layer is not able to detect or correct all errors.

Here is an example of how the transport layer can recover from an error that the data link layer is unable to detect:

1. The sender sends a packet to the receiver.
2. The packet is corrupted in transit.
3. The receiver receives the corrupted packet and sends an ACK back to the sender.
4. The sender does not receive an ACK for the packet within a certain amount of time.
5. The sender retransmits the packet.
6. The receiver receives the retransmitted packet and delivers it to the application.

In this example, the data link layer was unable to detect the error in the packet. However, the transport layer was able to recover from the error by retransmitting the packet.

Error control at the transport layer is essential for many applications, such as web browsers and email clients. Without error control at the transport layer, these applications would not be able to function properly.


#### The total amount of data piggybacked with SYN packet must be within specified limits. What is the specified limit? L3S7

The total amount of data piggybacked with the SYN packet in the TCP Fast Open (TFO) handshake must be less than or equal to 1460 bytes.

TFO is a handshake extension that allows the client to send data with the SYN packet. This can improve the performance of web browsing and other applications. However, it is important to limit the amount of data that is piggybacked with the SYN packet to prevent buffer overflows.

The limit of 1460 bytes is necessary because the SYN packet is used to establish the connection. If the SYN packet is too large, it may not be able to **fit in the** **buffer of the receive**r. This can cause the connection to fail.

In addition, the limit of 1460 bytes is necessary to prevent TFO from being used for **denial-of-service attacks**. If an attacker could piggyback a large amount of data with the SYN packet, they could cause the receiver to run out of memory and crash.

The limit of 1460 bytes is a reasonable compromise between performance and security**. It allows clients to send a small amount of data with the SYN packet, which can improve performance. However, it also prevents attackers from using TFO for denial-of-service attacks.

It is important to note that the limit of 1460 bytes is only for the data that is piggybacked with the SYN packet. The client can still send more data after the connection has been established.

Here is an example of how TFO works:

1. The client sends a SYN packet with the data that it wants to send.
2. The server receives the SYN packet and sends an SYN-ACK packet back to the client.
3. The client receives the SYN-ACK packet and sends an ACK packet back to the server.
4. The connection is now established and the client can send more data.

By using TFO, the client can send data to the server before the connection has been fully established. This can improve the performance of web browsing and other applications.

#### How do the client and server let each other know that they support TFO? L3S8

The client and server let each other know that they support TFO (TCP Fast Open) using the TCP options field in the SYN packet. The TCP options field is a variable-length field that can be used to carry additional information that is not part of the standard TCP header.

The TFO option is a 4-byte option. The first byte is the option code, which is 34. The second byte is the length of the option, which is always 16 bytes. The third and fourth bytes are padding, which are always 0.

The TFO option contains a cookie that is generated by the client. The server can use the cookie to verify that the client supports TFO.

If the server supports TFO, it will respond with a SYN-ACK packet that includes the TFO option. The server will also generate its own cookie and include it in the TFO option.

If both the client and server support TFO, they will be able to use TFO to improve the performance of the connection.


#### ICMP ‘Source Quench’: add fuel to the fire (this is an old concept, can it be tried now?)
ICMP Source Quench is an ICMP message that is sent from a router or host to a source host to notify the source host that it is sending packets too quickly and that it needs to slow down. The Source Quench message contains a parameter that indicates the next packet that the source host should send.

ICMP Source Quench was designed to help reduce congestion on the network. However, it was eventually deprecated because it was found to be ineffective and could actually make congestion worse.

One of the main problems with ICMP Source Quench is that it can be abused by attackers. For example, an attacker could send ICMP Source Quench packets to a legitimate user, causing them to slow down their traffic. This could make it difficult or impossible for the legitimate user to use the network.

Another problem with ICMP Source Quench is that it can be counterproductive. When a sender receives an ICMP Source Quench packet, it typically slows down its traffic. However, this can actually make congestion worse, because the sender is now sending smaller packets more frequently.

For these reasons, ICMP Source Quench is no longer used. Instead, modern networks use other methods to reduce congestion, such as congestion control algorithms and traffic shaping.

Here are some additional things to consider:

- ICMP Source Quench is not supported by all modern operating systems.
- ICMP Source Quench can be easily blocked by firewalls and other network devices.
- ICMP Source Quench can be abused by attackers to launch denial-of-service attacks.

Overall, there is little to no benefit to using ICMP Source Quench today. There are more effective and less risky ways to reduce congestion on a network.

#### The cwnd ‘doubles’ in approximately ‘one RTT’. How? ( Doubt )



#### Can we set values such as 2, 3 to this parameter (`slow_start_after_idle`) in Linux? If so, what does it mean? L5S10

Yes, you can set values such as 2, 3 to the parameter `slow_start_after_idle` in Linux. This parameter controls the number of RTTs that the sender will wait before entering the slow start phase after an idle period.

The default value for this parameter is 1. This means that the sender will enter the slow start phase after one RTT of idle time.

If you set the parameter to a higher value, then the sender will wait longer before entering the slow start phase. This can be useful for applications that need to maintain a high throughput, even after a period of inactivity.

For example, if you set the parameter to 2, then the sender will wait for two RTTs of idle time before entering the slow start phase. **This can be useful for applications that need to send a large burst of data after a period of inactivity, such as a file transfer program.**

However, it is important to note that increasing the value of this parameter can also increase the risk of congestion. If the sender waits too long before entering the slow start phase, then it could start sending data at a rate that is too high for the network to handle. This could lead to congestion and packet loss.

Therefore, it is important to choose a value for this parameter that is appropriate for your application and network environment.

Here is an example of how to set the parameter `slow_start_after_idle` in Linux:

```
sysctl -w net.ipv4.tcp_slow_start_after_idle=2
```

This will set the parameter to the value 2. You can also add this line to the file `/etc/sysctl.conf` to make the setting permanent.

Please note that you need to have root privileges to set this parameter.