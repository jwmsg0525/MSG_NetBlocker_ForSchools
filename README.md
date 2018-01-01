# MSG_NetBlocker_ForSchools
MSG_NetBlocker_ForSchools
<br>
This program is made by jaewan for Security School Netowrks.<br>
Nowadays, Schools' netowrks in korea are very weak for Unauthorized connection.<br>
Even, We can guess static ip forms by arp packet, or other PC's ip.<br>
So, We need what block the Unauthorized connection. <br>
This program is scan ip in  your Netowrks by ICMP packet, and check the mac address.<br>
If the mac address is unauthorized mac, It will send Block packet.<br>

<br>
This program will Done in january 1.<br>
comming soon!<br>

<h1>작동원리</h1>
Load whitelist into whitelist \<map\><br>
Send arp request all IPs and recive arp response.<br>
Extract IP and MAC address from arp response packet. <br>
and compare IP and MAC address with whitelist map.<br>
if there is no Matched IP and MAC address, the addresses add in blacklist \<map\><br>
and send arp response to blacklist devices change gateway macaddress.<br>
if the blacklist devices ricive the  arp resopnse packet, they can't use internet and other works in your network.<br>

<h1>how to write whitelist?</h1>
<pre>yourIP@yourMAC</pre>
