#cmd>> bash evalua.sh
cp src/main.cpp src/_main.cpp
for FILE in *tests/*/tad*.cpp ; do
	echo "Evaluando $FILE"
	cp $FILE src/main.cpp
        rm -f ./main
	make
	./main > $FILE.out
	diff -b -B -i $FILE.out $FILE.sal
	if [ "$?" == "0" ]; then
		echo "OK"
	else
		echo "ERROR"
	fi
	rm -f $FILE.out
done
cp src/_main.cpp src/main.cpp
rm -f src/_main.cpp
make clean