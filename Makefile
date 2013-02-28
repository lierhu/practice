CC	:= gcc
CXX	:= g++
LD	:= g++

CFLAGS	:=
LDFLAGS	:=
INCS	:=

OUTPUT :=

SRCS :=

OBJS := $(addsuffix .o,$(basename ${SRCS}))

${OUTPUT}: ${OBJS}
	${LD} -o $@ ${LDFLAGS} ${OBJS} ${LIBS} ${EXTRA_LIBS}

all:${OUTPUT}

exec:all
	./${OUTPUT}
clean:
	rm -f core ${OBJS} ${OUTPUT}

%.o: %.c
	${CC} -c ${CFLAGS} ${INCS} $< -o $@

%.o: %.cpp
	${CXX} -c ${CXXFLAGS} ${INCS} $< -o $@
