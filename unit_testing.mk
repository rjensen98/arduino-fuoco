##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Release
ProjectName            :=unit_testing
ConfigurationName      :=Release
WorkspacePath          := "C:\dev\arduino-fuoco"
ProjectPath            := "C:\dev\arduino-fuoco"
IntermediateDirectory  :=Release
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=RJensen
Date                   :=12/09/14
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
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="unit_testing.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :="C:/apps/MinGW-4.8.1/bin/windres.exe" 
LinkOptions            :=  -O2
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch)$(WorkspacePath)/arduino_files $(IncludeSwitch). $(IncludeSwitch)$(UNIT_TEST_PP_SRC_DIR)/src $(IncludeSwitch)$(WorkspacePath)/arduino_files $(IncludeSwitch)$(WorkspacePath)/include 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)UnitTest++ $(LibrarySwitch)arduino_fuoco 
ArLibs                 :=  "libUnitTest++.a" "libarduino_fuoco.a" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)$(UNIT_TEST_PP_SRC_DIR)/Release $(LibraryPathSwitch)$(WorkspacePath)/arduino_files 

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
Objects0=$(IntermediateDirectory)/test_main.cpp$(ObjectSuffix) $(IntermediateDirectory)/test_includes_AssertException.cpp$(ObjectSuffix) $(IntermediateDirectory)/test_includes_Checks.cpp$(ObjectSuffix) $(IntermediateDirectory)/test_includes_DeferredTestReporter.cpp$(ObjectSuffix) $(IntermediateDirectory)/test_includes_DeferredTestResult.cpp$(ObjectSuffix) $(IntermediateDirectory)/test_includes_MemoryOutStream.cpp$(ObjectSuffix) $(IntermediateDirectory)/test_includes_ReportAssert.cpp$(ObjectSuffix) $(IntermediateDirectory)/test_includes_Test.cpp$(ObjectSuffix) $(IntermediateDirectory)/test_includes_TestDetails.cpp$(ObjectSuffix) $(IntermediateDirectory)/test_includes_TestList.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/test_includes_TestReporter.cpp$(ObjectSuffix) $(IntermediateDirectory)/test_includes_TestReporterStdout.cpp$(ObjectSuffix) $(IntermediateDirectory)/test_includes_TestResults.cpp$(ObjectSuffix) $(IntermediateDirectory)/test_includes_TestRunner.cpp$(ObjectSuffix) $(IntermediateDirectory)/test_includes_TimeConstraint.cpp$(ObjectSuffix) $(IntermediateDirectory)/test_includes_XmlTestReporter.cpp$(ObjectSuffix) $(IntermediateDirectory)/entity_testAFTime.cpp$(ObjectSuffix) $(IntermediateDirectory)/entity_testZone.cpp$(ObjectSuffix) $(IntermediateDirectory)/entity_testCirculator.cpp$(ObjectSuffix) $(IntermediateDirectory)/entity_testMenu.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/entity_testMenuData.cpp$(ObjectSuffix) $(IntermediateDirectory)/utility_testStringHelper.cpp$(ObjectSuffix) $(IntermediateDirectory)/utility_testZoneListHelper.cpp$(ObjectSuffix) $(IntermediateDirectory)/utility_testTimeDefinitionHelper.cpp$(ObjectSuffix) $(IntermediateDirectory)/controllers_testHeatController.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d ".build-release\arduino_fuoco" $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

".build-release\arduino_fuoco":
	@$(MakeDirCommand) ".build-release"
	@echo stam > ".build-release\arduino_fuoco"




$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "Release"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/test_main.cpp$(ObjectSuffix): src/test/main.cpp $(IntermediateDirectory)/test_main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/dev/arduino-fuoco/src/test/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/test_main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/test_main.cpp$(DependSuffix): src/test/main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/test_main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/test_main.cpp$(DependSuffix) -MM "src/test/main.cpp"

$(IntermediateDirectory)/test_main.cpp$(PreprocessSuffix): src/test/main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/test_main.cpp$(PreprocessSuffix) "src/test/main.cpp"

$(IntermediateDirectory)/test_includes_AssertException.cpp$(ObjectSuffix): src/test/test_includes/AssertException.cpp $(IntermediateDirectory)/test_includes_AssertException.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/dev/arduino-fuoco/src/test/test_includes/AssertException.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/test_includes_AssertException.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/test_includes_AssertException.cpp$(DependSuffix): src/test/test_includes/AssertException.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/test_includes_AssertException.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/test_includes_AssertException.cpp$(DependSuffix) -MM "src/test/test_includes/AssertException.cpp"

$(IntermediateDirectory)/test_includes_AssertException.cpp$(PreprocessSuffix): src/test/test_includes/AssertException.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/test_includes_AssertException.cpp$(PreprocessSuffix) "src/test/test_includes/AssertException.cpp"

$(IntermediateDirectory)/test_includes_Checks.cpp$(ObjectSuffix): src/test/test_includes/Checks.cpp $(IntermediateDirectory)/test_includes_Checks.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/dev/arduino-fuoco/src/test/test_includes/Checks.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/test_includes_Checks.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/test_includes_Checks.cpp$(DependSuffix): src/test/test_includes/Checks.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/test_includes_Checks.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/test_includes_Checks.cpp$(DependSuffix) -MM "src/test/test_includes/Checks.cpp"

$(IntermediateDirectory)/test_includes_Checks.cpp$(PreprocessSuffix): src/test/test_includes/Checks.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/test_includes_Checks.cpp$(PreprocessSuffix) "src/test/test_includes/Checks.cpp"

$(IntermediateDirectory)/test_includes_DeferredTestReporter.cpp$(ObjectSuffix): src/test/test_includes/DeferredTestReporter.cpp $(IntermediateDirectory)/test_includes_DeferredTestReporter.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/dev/arduino-fuoco/src/test/test_includes/DeferredTestReporter.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/test_includes_DeferredTestReporter.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/test_includes_DeferredTestReporter.cpp$(DependSuffix): src/test/test_includes/DeferredTestReporter.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/test_includes_DeferredTestReporter.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/test_includes_DeferredTestReporter.cpp$(DependSuffix) -MM "src/test/test_includes/DeferredTestReporter.cpp"

$(IntermediateDirectory)/test_includes_DeferredTestReporter.cpp$(PreprocessSuffix): src/test/test_includes/DeferredTestReporter.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/test_includes_DeferredTestReporter.cpp$(PreprocessSuffix) "src/test/test_includes/DeferredTestReporter.cpp"

$(IntermediateDirectory)/test_includes_DeferredTestResult.cpp$(ObjectSuffix): src/test/test_includes/DeferredTestResult.cpp $(IntermediateDirectory)/test_includes_DeferredTestResult.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/dev/arduino-fuoco/src/test/test_includes/DeferredTestResult.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/test_includes_DeferredTestResult.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/test_includes_DeferredTestResult.cpp$(DependSuffix): src/test/test_includes/DeferredTestResult.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/test_includes_DeferredTestResult.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/test_includes_DeferredTestResult.cpp$(DependSuffix) -MM "src/test/test_includes/DeferredTestResult.cpp"

$(IntermediateDirectory)/test_includes_DeferredTestResult.cpp$(PreprocessSuffix): src/test/test_includes/DeferredTestResult.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/test_includes_DeferredTestResult.cpp$(PreprocessSuffix) "src/test/test_includes/DeferredTestResult.cpp"

$(IntermediateDirectory)/test_includes_MemoryOutStream.cpp$(ObjectSuffix): src/test/test_includes/MemoryOutStream.cpp $(IntermediateDirectory)/test_includes_MemoryOutStream.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/dev/arduino-fuoco/src/test/test_includes/MemoryOutStream.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/test_includes_MemoryOutStream.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/test_includes_MemoryOutStream.cpp$(DependSuffix): src/test/test_includes/MemoryOutStream.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/test_includes_MemoryOutStream.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/test_includes_MemoryOutStream.cpp$(DependSuffix) -MM "src/test/test_includes/MemoryOutStream.cpp"

$(IntermediateDirectory)/test_includes_MemoryOutStream.cpp$(PreprocessSuffix): src/test/test_includes/MemoryOutStream.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/test_includes_MemoryOutStream.cpp$(PreprocessSuffix) "src/test/test_includes/MemoryOutStream.cpp"

$(IntermediateDirectory)/test_includes_ReportAssert.cpp$(ObjectSuffix): src/test/test_includes/ReportAssert.cpp $(IntermediateDirectory)/test_includes_ReportAssert.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/dev/arduino-fuoco/src/test/test_includes/ReportAssert.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/test_includes_ReportAssert.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/test_includes_ReportAssert.cpp$(DependSuffix): src/test/test_includes/ReportAssert.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/test_includes_ReportAssert.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/test_includes_ReportAssert.cpp$(DependSuffix) -MM "src/test/test_includes/ReportAssert.cpp"

$(IntermediateDirectory)/test_includes_ReportAssert.cpp$(PreprocessSuffix): src/test/test_includes/ReportAssert.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/test_includes_ReportAssert.cpp$(PreprocessSuffix) "src/test/test_includes/ReportAssert.cpp"

$(IntermediateDirectory)/test_includes_Test.cpp$(ObjectSuffix): src/test/test_includes/Test.cpp $(IntermediateDirectory)/test_includes_Test.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/dev/arduino-fuoco/src/test/test_includes/Test.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/test_includes_Test.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/test_includes_Test.cpp$(DependSuffix): src/test/test_includes/Test.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/test_includes_Test.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/test_includes_Test.cpp$(DependSuffix) -MM "src/test/test_includes/Test.cpp"

$(IntermediateDirectory)/test_includes_Test.cpp$(PreprocessSuffix): src/test/test_includes/Test.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/test_includes_Test.cpp$(PreprocessSuffix) "src/test/test_includes/Test.cpp"

$(IntermediateDirectory)/test_includes_TestDetails.cpp$(ObjectSuffix): src/test/test_includes/TestDetails.cpp $(IntermediateDirectory)/test_includes_TestDetails.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/dev/arduino-fuoco/src/test/test_includes/TestDetails.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/test_includes_TestDetails.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/test_includes_TestDetails.cpp$(DependSuffix): src/test/test_includes/TestDetails.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/test_includes_TestDetails.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/test_includes_TestDetails.cpp$(DependSuffix) -MM "src/test/test_includes/TestDetails.cpp"

$(IntermediateDirectory)/test_includes_TestDetails.cpp$(PreprocessSuffix): src/test/test_includes/TestDetails.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/test_includes_TestDetails.cpp$(PreprocessSuffix) "src/test/test_includes/TestDetails.cpp"

$(IntermediateDirectory)/test_includes_TestList.cpp$(ObjectSuffix): src/test/test_includes/TestList.cpp $(IntermediateDirectory)/test_includes_TestList.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/dev/arduino-fuoco/src/test/test_includes/TestList.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/test_includes_TestList.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/test_includes_TestList.cpp$(DependSuffix): src/test/test_includes/TestList.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/test_includes_TestList.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/test_includes_TestList.cpp$(DependSuffix) -MM "src/test/test_includes/TestList.cpp"

$(IntermediateDirectory)/test_includes_TestList.cpp$(PreprocessSuffix): src/test/test_includes/TestList.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/test_includes_TestList.cpp$(PreprocessSuffix) "src/test/test_includes/TestList.cpp"

$(IntermediateDirectory)/test_includes_TestReporter.cpp$(ObjectSuffix): src/test/test_includes/TestReporter.cpp $(IntermediateDirectory)/test_includes_TestReporter.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/dev/arduino-fuoco/src/test/test_includes/TestReporter.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/test_includes_TestReporter.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/test_includes_TestReporter.cpp$(DependSuffix): src/test/test_includes/TestReporter.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/test_includes_TestReporter.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/test_includes_TestReporter.cpp$(DependSuffix) -MM "src/test/test_includes/TestReporter.cpp"

$(IntermediateDirectory)/test_includes_TestReporter.cpp$(PreprocessSuffix): src/test/test_includes/TestReporter.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/test_includes_TestReporter.cpp$(PreprocessSuffix) "src/test/test_includes/TestReporter.cpp"

$(IntermediateDirectory)/test_includes_TestReporterStdout.cpp$(ObjectSuffix): src/test/test_includes/TestReporterStdout.cpp $(IntermediateDirectory)/test_includes_TestReporterStdout.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/dev/arduino-fuoco/src/test/test_includes/TestReporterStdout.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/test_includes_TestReporterStdout.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/test_includes_TestReporterStdout.cpp$(DependSuffix): src/test/test_includes/TestReporterStdout.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/test_includes_TestReporterStdout.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/test_includes_TestReporterStdout.cpp$(DependSuffix) -MM "src/test/test_includes/TestReporterStdout.cpp"

$(IntermediateDirectory)/test_includes_TestReporterStdout.cpp$(PreprocessSuffix): src/test/test_includes/TestReporterStdout.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/test_includes_TestReporterStdout.cpp$(PreprocessSuffix) "src/test/test_includes/TestReporterStdout.cpp"

$(IntermediateDirectory)/test_includes_TestResults.cpp$(ObjectSuffix): src/test/test_includes/TestResults.cpp $(IntermediateDirectory)/test_includes_TestResults.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/dev/arduino-fuoco/src/test/test_includes/TestResults.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/test_includes_TestResults.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/test_includes_TestResults.cpp$(DependSuffix): src/test/test_includes/TestResults.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/test_includes_TestResults.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/test_includes_TestResults.cpp$(DependSuffix) -MM "src/test/test_includes/TestResults.cpp"

$(IntermediateDirectory)/test_includes_TestResults.cpp$(PreprocessSuffix): src/test/test_includes/TestResults.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/test_includes_TestResults.cpp$(PreprocessSuffix) "src/test/test_includes/TestResults.cpp"

$(IntermediateDirectory)/test_includes_TestRunner.cpp$(ObjectSuffix): src/test/test_includes/TestRunner.cpp $(IntermediateDirectory)/test_includes_TestRunner.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/dev/arduino-fuoco/src/test/test_includes/TestRunner.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/test_includes_TestRunner.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/test_includes_TestRunner.cpp$(DependSuffix): src/test/test_includes/TestRunner.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/test_includes_TestRunner.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/test_includes_TestRunner.cpp$(DependSuffix) -MM "src/test/test_includes/TestRunner.cpp"

$(IntermediateDirectory)/test_includes_TestRunner.cpp$(PreprocessSuffix): src/test/test_includes/TestRunner.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/test_includes_TestRunner.cpp$(PreprocessSuffix) "src/test/test_includes/TestRunner.cpp"

$(IntermediateDirectory)/test_includes_TimeConstraint.cpp$(ObjectSuffix): src/test/test_includes/TimeConstraint.cpp $(IntermediateDirectory)/test_includes_TimeConstraint.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/dev/arduino-fuoco/src/test/test_includes/TimeConstraint.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/test_includes_TimeConstraint.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/test_includes_TimeConstraint.cpp$(DependSuffix): src/test/test_includes/TimeConstraint.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/test_includes_TimeConstraint.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/test_includes_TimeConstraint.cpp$(DependSuffix) -MM "src/test/test_includes/TimeConstraint.cpp"

$(IntermediateDirectory)/test_includes_TimeConstraint.cpp$(PreprocessSuffix): src/test/test_includes/TimeConstraint.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/test_includes_TimeConstraint.cpp$(PreprocessSuffix) "src/test/test_includes/TimeConstraint.cpp"

$(IntermediateDirectory)/test_includes_XmlTestReporter.cpp$(ObjectSuffix): src/test/test_includes/XmlTestReporter.cpp $(IntermediateDirectory)/test_includes_XmlTestReporter.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/dev/arduino-fuoco/src/test/test_includes/XmlTestReporter.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/test_includes_XmlTestReporter.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/test_includes_XmlTestReporter.cpp$(DependSuffix): src/test/test_includes/XmlTestReporter.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/test_includes_XmlTestReporter.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/test_includes_XmlTestReporter.cpp$(DependSuffix) -MM "src/test/test_includes/XmlTestReporter.cpp"

$(IntermediateDirectory)/test_includes_XmlTestReporter.cpp$(PreprocessSuffix): src/test/test_includes/XmlTestReporter.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/test_includes_XmlTestReporter.cpp$(PreprocessSuffix) "src/test/test_includes/XmlTestReporter.cpp"

$(IntermediateDirectory)/entity_testAFTime.cpp$(ObjectSuffix): src/test/arduino_fuoco/entity/testAFTime.cpp $(IntermediateDirectory)/entity_testAFTime.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/dev/arduino-fuoco/src/test/arduino_fuoco/entity/testAFTime.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/entity_testAFTime.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/entity_testAFTime.cpp$(DependSuffix): src/test/arduino_fuoco/entity/testAFTime.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/entity_testAFTime.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/entity_testAFTime.cpp$(DependSuffix) -MM "src/test/arduino_fuoco/entity/testAFTime.cpp"

$(IntermediateDirectory)/entity_testAFTime.cpp$(PreprocessSuffix): src/test/arduino_fuoco/entity/testAFTime.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/entity_testAFTime.cpp$(PreprocessSuffix) "src/test/arduino_fuoco/entity/testAFTime.cpp"

$(IntermediateDirectory)/entity_testZone.cpp$(ObjectSuffix): src/test/arduino_fuoco/entity/testZone.cpp $(IntermediateDirectory)/entity_testZone.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/dev/arduino-fuoco/src/test/arduino_fuoco/entity/testZone.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/entity_testZone.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/entity_testZone.cpp$(DependSuffix): src/test/arduino_fuoco/entity/testZone.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/entity_testZone.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/entity_testZone.cpp$(DependSuffix) -MM "src/test/arduino_fuoco/entity/testZone.cpp"

$(IntermediateDirectory)/entity_testZone.cpp$(PreprocessSuffix): src/test/arduino_fuoco/entity/testZone.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/entity_testZone.cpp$(PreprocessSuffix) "src/test/arduino_fuoco/entity/testZone.cpp"

$(IntermediateDirectory)/entity_testCirculator.cpp$(ObjectSuffix): src/test/arduino_fuoco/entity/testCirculator.cpp $(IntermediateDirectory)/entity_testCirculator.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/dev/arduino-fuoco/src/test/arduino_fuoco/entity/testCirculator.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/entity_testCirculator.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/entity_testCirculator.cpp$(DependSuffix): src/test/arduino_fuoco/entity/testCirculator.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/entity_testCirculator.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/entity_testCirculator.cpp$(DependSuffix) -MM "src/test/arduino_fuoco/entity/testCirculator.cpp"

$(IntermediateDirectory)/entity_testCirculator.cpp$(PreprocessSuffix): src/test/arduino_fuoco/entity/testCirculator.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/entity_testCirculator.cpp$(PreprocessSuffix) "src/test/arduino_fuoco/entity/testCirculator.cpp"

$(IntermediateDirectory)/entity_testMenu.cpp$(ObjectSuffix): src/test/arduino_fuoco/entity/testMenu.cpp $(IntermediateDirectory)/entity_testMenu.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/dev/arduino-fuoco/src/test/arduino_fuoco/entity/testMenu.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/entity_testMenu.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/entity_testMenu.cpp$(DependSuffix): src/test/arduino_fuoco/entity/testMenu.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/entity_testMenu.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/entity_testMenu.cpp$(DependSuffix) -MM "src/test/arduino_fuoco/entity/testMenu.cpp"

$(IntermediateDirectory)/entity_testMenu.cpp$(PreprocessSuffix): src/test/arduino_fuoco/entity/testMenu.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/entity_testMenu.cpp$(PreprocessSuffix) "src/test/arduino_fuoco/entity/testMenu.cpp"

$(IntermediateDirectory)/entity_testMenuData.cpp$(ObjectSuffix): src/test/arduino_fuoco/entity/testMenuData.cpp $(IntermediateDirectory)/entity_testMenuData.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/dev/arduino-fuoco/src/test/arduino_fuoco/entity/testMenuData.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/entity_testMenuData.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/entity_testMenuData.cpp$(DependSuffix): src/test/arduino_fuoco/entity/testMenuData.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/entity_testMenuData.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/entity_testMenuData.cpp$(DependSuffix) -MM "src/test/arduino_fuoco/entity/testMenuData.cpp"

$(IntermediateDirectory)/entity_testMenuData.cpp$(PreprocessSuffix): src/test/arduino_fuoco/entity/testMenuData.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/entity_testMenuData.cpp$(PreprocessSuffix) "src/test/arduino_fuoco/entity/testMenuData.cpp"

$(IntermediateDirectory)/utility_testStringHelper.cpp$(ObjectSuffix): src/test/arduino_fuoco/utility/testStringHelper.cpp $(IntermediateDirectory)/utility_testStringHelper.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/dev/arduino-fuoco/src/test/arduino_fuoco/utility/testStringHelper.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/utility_testStringHelper.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/utility_testStringHelper.cpp$(DependSuffix): src/test/arduino_fuoco/utility/testStringHelper.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/utility_testStringHelper.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/utility_testStringHelper.cpp$(DependSuffix) -MM "src/test/arduino_fuoco/utility/testStringHelper.cpp"

$(IntermediateDirectory)/utility_testStringHelper.cpp$(PreprocessSuffix): src/test/arduino_fuoco/utility/testStringHelper.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/utility_testStringHelper.cpp$(PreprocessSuffix) "src/test/arduino_fuoco/utility/testStringHelper.cpp"

$(IntermediateDirectory)/utility_testZoneListHelper.cpp$(ObjectSuffix): src/test/arduino_fuoco/utility/testZoneListHelper.cpp $(IntermediateDirectory)/utility_testZoneListHelper.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/dev/arduino-fuoco/src/test/arduino_fuoco/utility/testZoneListHelper.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/utility_testZoneListHelper.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/utility_testZoneListHelper.cpp$(DependSuffix): src/test/arduino_fuoco/utility/testZoneListHelper.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/utility_testZoneListHelper.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/utility_testZoneListHelper.cpp$(DependSuffix) -MM "src/test/arduino_fuoco/utility/testZoneListHelper.cpp"

$(IntermediateDirectory)/utility_testZoneListHelper.cpp$(PreprocessSuffix): src/test/arduino_fuoco/utility/testZoneListHelper.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/utility_testZoneListHelper.cpp$(PreprocessSuffix) "src/test/arduino_fuoco/utility/testZoneListHelper.cpp"

$(IntermediateDirectory)/utility_testTimeDefinitionHelper.cpp$(ObjectSuffix): src/test/arduino_fuoco/utility/testTimeDefinitionHelper.cpp $(IntermediateDirectory)/utility_testTimeDefinitionHelper.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/dev/arduino-fuoco/src/test/arduino_fuoco/utility/testTimeDefinitionHelper.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/utility_testTimeDefinitionHelper.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/utility_testTimeDefinitionHelper.cpp$(DependSuffix): src/test/arduino_fuoco/utility/testTimeDefinitionHelper.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/utility_testTimeDefinitionHelper.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/utility_testTimeDefinitionHelper.cpp$(DependSuffix) -MM "src/test/arduino_fuoco/utility/testTimeDefinitionHelper.cpp"

$(IntermediateDirectory)/utility_testTimeDefinitionHelper.cpp$(PreprocessSuffix): src/test/arduino_fuoco/utility/testTimeDefinitionHelper.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/utility_testTimeDefinitionHelper.cpp$(PreprocessSuffix) "src/test/arduino_fuoco/utility/testTimeDefinitionHelper.cpp"

$(IntermediateDirectory)/controllers_testHeatController.cpp$(ObjectSuffix): src/test/arduino_fuoco/controllers/testHeatController.cpp $(IntermediateDirectory)/controllers_testHeatController.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/dev/arduino-fuoco/src/test/arduino_fuoco/controllers/testHeatController.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/controllers_testHeatController.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/controllers_testHeatController.cpp$(DependSuffix): src/test/arduino_fuoco/controllers/testHeatController.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/controllers_testHeatController.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/controllers_testHeatController.cpp$(DependSuffix) -MM "src/test/arduino_fuoco/controllers/testHeatController.cpp"

$(IntermediateDirectory)/controllers_testHeatController.cpp$(PreprocessSuffix): src/test/arduino_fuoco/controllers/testHeatController.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/controllers_testHeatController.cpp$(PreprocessSuffix) "src/test/arduino_fuoco/controllers/testHeatController.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) Release/*$(ObjectSuffix)
	$(RM) Release/*$(DependSuffix)
	$(RM) $(OutputFile)
	$(RM) $(OutputFile).exe
	$(RM) ".build-release/unit_testing"


