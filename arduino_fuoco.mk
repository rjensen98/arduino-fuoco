##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=arduino_fuoco
ConfigurationName      :=Debug
WorkspacePath          := "C:\dev\arduino-fuoco"
ProjectPath            := "C:\dev\arduino-fuoco"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=RJensen
Date                   :=09/01/14
CodeLitePath           :="C:\apps\CodeLite"
LinkerName             :="C:/apps/MinGW-4.8.1/bin/g++.exe" 
SharedObjectLinkerName :="C:/apps/MinGW-4.8.1/bin/g++.exe" -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/lib$(ProjectName).a
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="arduino_fuoco.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :="C:/apps/MinGW-4.8.1/bin/windres.exe" 
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch)$(IntermediateDirectory)/../include/ $(IncludeSwitch)$(IntermediateDirectory)/../src/main/arduino_fuoco/entity/ $(IncludeSwitch)$(IntermediateDirectory)/../src/main/arduino_fuoco/enums/ $(IncludeSwitch)$(IntermediateDirectory)/../src/main/arduino_fuoco/config $(IncludeSwitch)$(IntermediateDirectory)/../src/main/arduino_fuoco/controllers/ $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := "C:/apps/MinGW-4.8.1/bin/ar.exe" rcu
CXX      := "C:/apps/MinGW-4.8.1/bin/g++.exe" 
CC       := "C:/apps/MinGW-4.8.1/bin/gcc.exe" 
CXXFLAGS :=  -g $(Preprocessors)
CFLAGS   :=  -g $(Preprocessors)
ASFLAGS  := 
AS       := "C:/apps/MinGW-4.8.1/bin/as.exe" 


##
## User defined environment variables
##
CodeLiteDir:=C:\apps\CodeLite
UNIT_TEST_PP_SRC_DIR:=C:/apps/UnitTest++-1.3
Objects0=$(IntermediateDirectory)/include_Arduino.cpp$(ObjectSuffix) $(IntermediateDirectory)/controllers_HeatController.cpp$(ObjectSuffix) $(IntermediateDirectory)/entity_Zone.cpp$(ObjectSuffix) $(IntermediateDirectory)/entity_ZoneSetting.cpp$(ObjectSuffix) $(IntermediateDirectory)/entity_TimeDefinition.cpp$(ObjectSuffix) $(IntermediateDirectory)/entity_AFTime.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(IntermediateDirectory) $(OutputFile)

$(OutputFile): $(Objects)
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(AR) $(ArchiveOutputSwitch)$(OutputFile) @$(ObjectsFileList) $(ArLibs)
	@$(MakeDirCommand) "C:\dev\arduino-fuoco/.build-debug"
	@echo rebuilt > "C:\dev\arduino-fuoco/.build-debug/arduino_fuoco"

PostBuild:
	@echo Executing Post Build commands ...
	pushd $(WorkspacePath)\src\main
	for /R %%x in (*.cpp) do copy "%%x" "$(WorkspacePath)\arduino_files"
	for /R %%x in (*.h) do copy "%%x" "$(WorkspacePath)\arduino_files"
	popd
	@echo Done

./Debug:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/include_Arduino.cpp$(ObjectSuffix): include/Arduino.cpp $(IntermediateDirectory)/include_Arduino.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/dev/arduino-fuoco/include/Arduino.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/include_Arduino.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/include_Arduino.cpp$(DependSuffix): include/Arduino.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/include_Arduino.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/include_Arduino.cpp$(DependSuffix) -MM "include/Arduino.cpp"

$(IntermediateDirectory)/include_Arduino.cpp$(PreprocessSuffix): include/Arduino.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/include_Arduino.cpp$(PreprocessSuffix) "include/Arduino.cpp"

$(IntermediateDirectory)/controllers_HeatController.cpp$(ObjectSuffix): src/main/arduino_fuoco/controllers/HeatController.cpp $(IntermediateDirectory)/controllers_HeatController.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/dev/arduino-fuoco/src/main/arduino_fuoco/controllers/HeatController.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/controllers_HeatController.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/controllers_HeatController.cpp$(DependSuffix): src/main/arduino_fuoco/controllers/HeatController.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/controllers_HeatController.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/controllers_HeatController.cpp$(DependSuffix) -MM "src/main/arduino_fuoco/controllers/HeatController.cpp"

$(IntermediateDirectory)/controllers_HeatController.cpp$(PreprocessSuffix): src/main/arduino_fuoco/controllers/HeatController.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/controllers_HeatController.cpp$(PreprocessSuffix) "src/main/arduino_fuoco/controllers/HeatController.cpp"

$(IntermediateDirectory)/entity_Zone.cpp$(ObjectSuffix): src/main/arduino_fuoco/entity/Zone.cpp $(IntermediateDirectory)/entity_Zone.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/dev/arduino-fuoco/src/main/arduino_fuoco/entity/Zone.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/entity_Zone.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/entity_Zone.cpp$(DependSuffix): src/main/arduino_fuoco/entity/Zone.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/entity_Zone.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/entity_Zone.cpp$(DependSuffix) -MM "src/main/arduino_fuoco/entity/Zone.cpp"

$(IntermediateDirectory)/entity_Zone.cpp$(PreprocessSuffix): src/main/arduino_fuoco/entity/Zone.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/entity_Zone.cpp$(PreprocessSuffix) "src/main/arduino_fuoco/entity/Zone.cpp"

$(IntermediateDirectory)/entity_ZoneSetting.cpp$(ObjectSuffix): src/main/arduino_fuoco/entity/ZoneSetting.cpp $(IntermediateDirectory)/entity_ZoneSetting.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/dev/arduino-fuoco/src/main/arduino_fuoco/entity/ZoneSetting.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/entity_ZoneSetting.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/entity_ZoneSetting.cpp$(DependSuffix): src/main/arduino_fuoco/entity/ZoneSetting.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/entity_ZoneSetting.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/entity_ZoneSetting.cpp$(DependSuffix) -MM "src/main/arduino_fuoco/entity/ZoneSetting.cpp"

$(IntermediateDirectory)/entity_ZoneSetting.cpp$(PreprocessSuffix): src/main/arduino_fuoco/entity/ZoneSetting.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/entity_ZoneSetting.cpp$(PreprocessSuffix) "src/main/arduino_fuoco/entity/ZoneSetting.cpp"

$(IntermediateDirectory)/entity_TimeDefinition.cpp$(ObjectSuffix): src/main/arduino_fuoco/entity/TimeDefinition.cpp $(IntermediateDirectory)/entity_TimeDefinition.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/dev/arduino-fuoco/src/main/arduino_fuoco/entity/TimeDefinition.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/entity_TimeDefinition.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/entity_TimeDefinition.cpp$(DependSuffix): src/main/arduino_fuoco/entity/TimeDefinition.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/entity_TimeDefinition.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/entity_TimeDefinition.cpp$(DependSuffix) -MM "src/main/arduino_fuoco/entity/TimeDefinition.cpp"

$(IntermediateDirectory)/entity_TimeDefinition.cpp$(PreprocessSuffix): src/main/arduino_fuoco/entity/TimeDefinition.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/entity_TimeDefinition.cpp$(PreprocessSuffix) "src/main/arduino_fuoco/entity/TimeDefinition.cpp"

$(IntermediateDirectory)/entity_AFTime.cpp$(ObjectSuffix): src/main/arduino_fuoco/entity/AFTime.cpp $(IntermediateDirectory)/entity_AFTime.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/dev/arduino-fuoco/src/main/arduino_fuoco/entity/AFTime.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/entity_AFTime.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/entity_AFTime.cpp$(DependSuffix): src/main/arduino_fuoco/entity/AFTime.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/entity_AFTime.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/entity_AFTime.cpp$(DependSuffix) -MM "src/main/arduino_fuoco/entity/AFTime.cpp"

$(IntermediateDirectory)/entity_AFTime.cpp$(PreprocessSuffix): src/main/arduino_fuoco/entity/AFTime.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/entity_AFTime.cpp$(PreprocessSuffix) "src/main/arduino_fuoco/entity/AFTime.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) ./Debug/*$(ObjectSuffix)
	$(RM) ./Debug/*$(DependSuffix)
	$(RM) $(OutputFile)
	$(RM) $(OutputFile)
	$(RM) ".build-debug/arduino_fuoco"


