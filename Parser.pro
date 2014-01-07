TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -std=c++11 -Wall -Wextra -pedantic



INCLUDEPATH += src

SOURCES += \
		src/Main.cpp \
		src/Process.cpp \
		src/StructureWriter.cpp \
		src/parser/Parser.cpp \
		src/parser/LexemesList.cpp \
		src/parser/lexemes/Lexeme.cpp \
		src/parser/lexemes/ValueLexeme.cpp \
		src/parser/lexemes/NameLexeme.cpp \
		src/parser/lexemes/ListEndLexeme.cpp \
		src/parser/lexemes/AssignLexeme.cpp \
		src/parser/lexemes/ListBeginLexeme.cpp \
		src/parser/utils/Utils.cpp \
		src/parser/utils/LexemesPairsMatchChecker.cpp \
		src/utils/FileReadWrite.cpp \
		src/utils/ConvertEncoding.cpp \
		src/utils/CommandLineOptions.cpp

HEADERS += \
		src/Process.h \
		src/StructureWriter.h \
		src/nodestree/BaseNode.hpp \
		src/nodestree/Node.hpp \
		src/nodestree/NodesTree.hpp \
		src/nodestree/UniversalNode.hpp \
		src/nodestree/Writer.hpp \
		src/parser/Parser.h \
		src/parser/Exceptions.h \
		src/parser/LexemesList.h \
		src/parser/lexemes/Lexeme.h \
		src/parser/lexemes/AssignLexeme.h \
		src/parser/lexemes/ListBeginLexeme.h \
		src/parser/lexemes/ListEndLexeme.h \
		src/parser/lexemes/NameLexeme.h \
		src/parser/lexemes/ValueLexeme.h \
		src/parser/utils/LexemesPairsMatchChecker.h \
		src/parser/utils/Utils.h \
		src/utils/FileReadWrite.h \
		src/utils/ConvertToString.hpp \
		src/utils/ConvertEndoding.h \
		src/utils/CommandLineOptions.h
