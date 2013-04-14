TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -std=c++11



INCLUDEPATH += Include

SOURCES += \
    Source/Process.cpp \
    Source/Main.cpp \
    Include/Rstyle/Parser/ValueLexeme.cpp \
    Include/Rstyle/Parser/Utils.cpp \
    Include/Rstyle/Parser/UniversalNode.cpp \
    Include/Rstyle/Parser/StructureWriter.cpp \
    Include/Rstyle/Parser/Parser.cpp \
    Include/Rstyle/Parser/NodesTree.cpp \
    Include/Rstyle/Parser/NameLexeme.cpp \
    Include/Rstyle/Parser/ListEndLexeme.cpp \
    Include/Rstyle/Parser/ListBeginLexeme.cpp \
    Include/Rstyle/Parser/LexemesPairsMatchChecker.cpp \
    Include/Rstyle/Parser/LexemesList.cpp \
    Include/Rstyle/Parser/AssignLexeme.cpp \
    Include/Simple/FileReadWrite.cpp \
    Include/Simple/ConvertEncoding.cpp \
		Include/Simple/CommandLineOptions.cpp \
    Include/Rstyle/Parser/Lexeme.cpp \
    Include/Rstyle/Parser/Node.cpp

HEADERS += \
    Source/Process.h \
    Include/Rstyle/Parser/Writer.h \
    Include/Rstyle/Parser/ValueLexeme.h \
    Include/Rstyle/Parser/Utils.h \
    Include/Rstyle/Parser/UniversalNode.h \
    Include/Rstyle/Parser/StructureWriter.h \
    Include/Rstyle/Parser/Parser.h \
    Include/Rstyle/Parser/NodesTree.h \
    Include/Rstyle/Parser/Node.h \
    Include/Rstyle/Parser/NameLexeme.h \
    Include/Rstyle/Parser/ListEndLexeme.h \
    Include/Rstyle/Parser/ListBeginLexeme.h \
    Include/Rstyle/Parser/LexemesPairsMatchChecker.h \
    Include/Rstyle/Parser/LexemesList.h \
    Include/Rstyle/Parser/Lexeme.h \
    Include/Rstyle/Parser/Exceptions.h \
    Include/Rstyle/Parser/AssignLexeme.h \
    Include/Simple/FileReadWrite.h \
    Include/Simple/ConvertToString.hpp \
    Include/Simple/ConvertEndoding.h \
		Include/Simple/CommandLineOptions.h
