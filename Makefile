fullwidth_conv:
	gcc -o fullwidth_conv fullwidth_conv.c

install: fullwidth_conv
	chmod +x fullwidth
	cp fullwidth /usr/local/bin
	cp fullwidth_conv /usr/local/bin

uninstall:
	rm /usr/local/bin/fullwidth
	rm /usr/local/bin/fullwidth_conv

clean:
	rm fullwidth_conv
