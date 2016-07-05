#Recursive Call to Individual Make

DIRS = dao assemblers

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
