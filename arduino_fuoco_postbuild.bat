SET mypath=%~dp0

cd arduino_files
del /q *.*

cd ..\src\main\
for /R %%x in (*.cpp) do copy "%%x" "%mypath%arduino_files"
for /R %%x in (*.h) do copy "%%x" "%mypath%arduino_files"

echo File export complete!
