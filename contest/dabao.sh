#!/bin/sh
rm XTYF-lzr.zip
mv $1 XTYF-lzr
zip -r XTYF-lzr.zip XTYF-lzr
mv XTYF-lzr $1
