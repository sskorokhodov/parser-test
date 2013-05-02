TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -std=c++11



INCLUDEPATH += Include

SOURCES += \
		source/Process.cpp \
		source/Main.cpp \
		source/StructureWriter.cpp \
		include/rstyle/parser/ValueLexeme.cpp \
		include/rstyle/parser/Utils.cpp \
		include/rstyle/parser/Parser.cpp \
		include/rstyle/parser/NameLexeme.cpp \
		include/rstyle/parser/ListEndLexeme.cpp \
		include/rstyle/parser/ListBeginLexeme.cpp \
		include/rstyle/parser/LexemesPairsMatchChecker.cpp \
		include/rstyle/parser/LexemesList.cpp \
		include/rstyle/parser/AssignLexeme.cpp \
		include/simple/FileReadWrite.cpp \
		include/simple/ConvertEncoding.cpp \
		include/simple/CommandLineOptions.cpp \
		include/rstyle/parser/Lexeme.cpp

HEADERS += \
		source/Process.h \
		source/StructureWriter.h \
		include/rstyle/nodetree/BaseNode.hpp \
		include/rstyle/nodetree/Node.hpp \
		include/rstyle/nodetree/NodesTree.hpp \
		include/rstyle/nodetree/UniversalNode.hpp \
		include/rstyle/parser/ValueLexeme.h \
		include/rstyle/parser/Utils.h \
		include/rstyle/parser/Parser.h \
		include/rstyle/parser/NameLexeme.h \
		include/rstyle/parser/ListEndLexeme.h \
		include/rstyle/parser/ListBeginLexeme.h \
		include/rstyle/parser/LexemesPairsMatchChecker.h \
		include/rstyle/parser/LexemesList.h \
		include/rstyle/parser/Lexeme.h \
		include/rstyle/parser/Exceptions.h \
		include/rstyle/parser/AssignLexeme.h \
		include/simple/FileReadWrite.h \
		include/simple/ConvertToString.hpp \
		include/simple/ConvertEndoding.h \
		include/simple/CommandLineOptions.h \
		include/rstyle/nodetree/Writer.hpp
