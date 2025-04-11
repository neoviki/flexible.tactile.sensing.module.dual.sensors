if upload fails in arduino do the following

sudo groupadd dialout
sudo gpasswd -a $USER dialout
sudo usermod -a -G dialout $USER
reboot ( must - after reboot it works )


