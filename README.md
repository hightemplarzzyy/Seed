# Seed
Seed Engine Development

SEED stands for:
Software Engineering Engine Development. (As out major is Software Engineering.)

The name also contains great wishes for our future, just as a seed will grow into something marvellous.

使用指南：
git命令行工具中，输入
git clone --recursive https://github.com/hightemplarzzyy/Seed X:/xxx/xxx（这里是你的目标路径）

之后运行generateprojects.bat，目前默认VS2017
如果使用VS2019，那么需要去premake官方下载最新的premake.exe，替代vendor/bin/premake5里同名文件，之后用记事本打开generateprojects.bat，将vs2017修改为vs2019。

之后运行生成好的seed.sln即可。
第一次编译成功之后运行，会提示缺少assimp.dll，去XXX/seed/vendor/assimp/win64里复制.dll和.lib文件到XXX/bin/Debug-windows-x86_64/Sandbox/目录下。
