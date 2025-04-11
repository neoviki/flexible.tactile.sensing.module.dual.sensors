rm -rf Gerber
rm Gerber.zip
mkdir Gerber
mv *.dri Gerber/
mv *.GBL Gerber/
mv *.GBO Gerber/
mv *.GBP Gerber/
mv *.GBS Gerber/
mv *.GKO Gerber/
mv *.gpi Gerber/
mv *.GTL Gerber/
mv *.GTO Gerber/
mv *.GTP Gerber/
mv *.GTS Gerber/
mv *.XLN Gerber/

echo "Gerber Files are copied to directory - Gerber, you can zip and upload to the manufacturer"