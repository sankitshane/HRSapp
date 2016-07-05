#Recursive Call to Individual Make

DIRS = src exe libs

all:
	for x in ${DIRS}; do \
	cd $$x; \
	make all;\
	cd ..;\
	done

clean:
	for x in ${DIRS}; do \
	cd $$x; \
	make clean;\
	cd ..;\
	done
