SOURCES=pat.scm sequence.scm atomic.scm verify.scm assignment-form.scm codegen.scm
OBJECTS=$(SOURCES:.scm=.so)

all: $(OBJECTS)
	csc spider.scm

$(OBJECTS): %.so: %.scm
	csc -sJ -o $@ $<
