@echo off
:loop
rand.exe//数据生成器
std.exe//程序1
aoj.exe//程序2
fc o.out oo.out
if not errorlevel 1 goto loop
pause
end