@echo off
pushd "%~1\lib\dns" || GOTO :ERR

echo gen.cmd: Generating 'enumtype.h', 'enumclass.h', 'rdatastruct.h'...

"%~2" -s . -t > include\dns\enumtype.h
"%~2" -s . -c > include\dns\enumclass.h
"%~2" -s . -i -P ./rdata/rdatastructpre.h -S ./rdata/rdatastructsuf.h > include\dns\rdatastruct.h
"%~2" -s . > code.h

GOTO :EOF

:ERR
exit /b 1
:EOF
