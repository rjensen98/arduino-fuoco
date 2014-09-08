##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Release
ProjectName            :=arduino_fuoco
ConfigurationName      :=Release
WorkspacePath          := "C:\dev\arduino-fuoco"
ProjectPath            := "C:\dev\arduino-fuoco"
IntermediateDirectory  :=./Release
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=RJensen
Date                   :=09/08/14
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
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch)$(IntermediateDirectory)/../include/ $(IncludeSwitch)$(IntermediateDirectory)/../src/main/arduino_fuoco/entity/ $(IncludeSwitch)$(IntermediateDirectory)/../src/main/arduino_fuoco/enums/ $(IncludeSwitch)$(IntermediateDirectory)/../src/main/arduino_fuoco/config $(IncludeSwitch)$(IntermediateDirectory)/../src/main/arduino_fuoco/controllers/ $(IncludeSwitch)$(IntermediateDirectory)/../src/main/arduino_fuoco/utility/ $(IncludeSwitch). 
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
CXXFLAGS :=   $(Preprocessors)
CFLAGS   :=   $(Preprocessors)
ASFLAGS  := 
AS       := "C:/apps/MinGW-4.8.1/bin/as.exe" 


##
## User defined environment variables
##
CodeLiteDir:=C:\apps\CodeLite
UNIT_TEST_PP_SRC_DIR:=C:/apps/UnitTest++-1.3
Objects0=$(IntermediateDirectory)/include_Arduino.cpp$(ObjectSuffix) $(IntermediateDirectory)/controllers_HeatController.cpp$(ObjectSuffix) $(IntermediateDirectory)/entity_Zone.cpp$(ObjectSuffix) $(IntermediateDirectory)/entity_ZoneSetting.cpp$(ObjectSuffix) $(IntermediateDirectory)/entity_TimeDefinition.cpp$(ObjectSuffix) $(IntermediateDirectory)/entity_AFTime.cpp$(ObjectSuffix) $(IntermediateDirectory)/entity_Circulator.cpp$(ObjectSuffix) $(IntermediateDirectory)/utility_StringHelper.cpp$(ObjectSuffix) $(IntermediateDirectory)/utility_AnalogHelper.cpp$(ObjectSuffix) 



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
	@$(MakeDirCommand) "C:\dev\arduino-fuoco/.build-release"
	@echo rebuilt > "C:\dev\arduino-fuoco/.build-release/arduino_fuoco"

PostBuild:
	@echo Executing Post Build commands ...
	$(WorkspacePath)\arduino_fuoco_postbuild.bat
	copy .\Release\libarduino_fuoco.a .\arduino_files
	@echo Done

./Release:
	@$(MakeDirCommand) "./Release"

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

$(IntermediateDirectory)/entity_Circulator.cpp$(ObjectSuffix): src/main/arduino_fuoco/entity/Circulator.cpp $(IntermediateDirectory)/entity_Circulator.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/dev/arduino-fuoco/src/main/arduino_fuoco/entity/Circulator.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/entity_Circulator.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/entity_Circulator.cpp$(DependSuffix): src/main/arduino_fuoco/entity/Circulator.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/entity_Circulator.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/entity_Circulator.cpp$(DependSuffix) -MM "src/main/arduino_fuoco/entity/Circulator.cpp"

$(IntermediateDirectory)/entity_Circulator.cpp$(PreprocessSuffix): src/main/arduino_fuoco/entity/Circulator.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/entity_Circulator.cpp$(PreprocessSuffix) "src/main/arduino_fuoco/entity/Circulator.cpp"

$(IntermediateDirectory)/utility_StringHelper.cpp$(ObjectSuffix): src/main/arduino_fuoco/utility/StringHelper.cpp $(IntermediateDirectory)/utility_StringHelper.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/dev/arduino-fuoco/src/main/arduino_fuoco/utility/StringHelper.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/utility_StringHelper.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/utility_StringHelper.cpp$(DependSuffix): src/main/arduino_fuoco/utility/StringHelper.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/utility_StringHelper.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/utility_StringHelper.cpp$(DependSuffix) -MM "src/main/arduino_fuoco/utility/StringHelper.cpp"

$(IntermediateDirectory)/utility_StringHelper.cpp$(PreprocessSuffix): src/main/arduino_fuoco/utility/StringHelper.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/utility_StringHelper.cpp$(PreprocessSuffix) "src/main/arduino_fuoco/utility/StringHelper.cpp"

$(IntermediateDirectory)/utility_AnalogHelper.cpp$(ObjectSuffix): src/main/arduino_fuoco/utility/AnalogHelper.cpp $(IntermediateDirectory)/utility_AnalogHelper.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/dev/arduino-fuoco/src/main/arduino_fuoco/utility/AnalogHelper.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/utility_AnalogHelper.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/utility_AnalogHelper.cpp$(DependSuffix): src/main/arduino_fuoco/utility/AnalogHelper.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/utility_AnalogHelper.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/utility_AnalogHelper.cpp$(DependSuffix) -MM "src/main/arduino_fuoco/utility/AnalogHelper.cpp"

$(IntermediateDirectory)/utility_AnalogHelper.cpp$(PreprocessSuffix): src/main/arduino_fuoco/utility/AnalogHelper.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/utility_AnalogHelper.cpp$(PreprocessSuffix) "src/main/arduino_fuoco/utility/AnalogHelper.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) ./Release/*$(ObjectSuffix)
	$(RM) ./Release/*$(DependSuffix)
	$(RM) $(OutputFile)
	$(RM) $(OutputFile)
	$(RM) ".build-release/arduino_fuoco"


