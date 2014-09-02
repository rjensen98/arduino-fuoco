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
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)$(UNIT_TEST_PP_SRC_DIR)/src 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)UnitTest++ 
ArLibs                 :=  "libUnitTest++.a" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)$(UNIT_TEST_PP_SRC_DIR)/Release 

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
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/test_includes_AssertException.cpp$(ObjectSuffix) $(IntermediateDirectory)/test_includes_Checks.cpp$(ObjectSuffix) $(IntermediateDirectory)/test_includes_DeferredTestReporter.cpp$(ObjectSuffix) $(IntermediateDirectory)/test_includes_DeferredTestResult.cpp$(ObjectSuffix) $(IntermediateDirectory)/test_includes_MemoryOutStream.cpp$(ObjectSuffix) $(IntermediateDirectory)/test_includes_ReportAssert.cpp$(ObjectSuffix) $(IntermediateDirectory)/test_includes_Test.cpp$(ObjectSuffix) $(IntermediateDirectory)/test_includes_TestDetails.cpp$(ObjectSuffix) $(IntermediateDirectory)/test_includes_TestList.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/test_includes_TestReporter.cpp$(ObjectSuffix) $(IntermediateDirectory)/test_includes_TestReporterStdout.cpp$(ObjectSuffix) $(IntermediateDirectory)/test_includes_TestResults.cpp$(ObjectSuffix) $(IntermediateDirectory)/test_includes_TestRunner.cpp$(ObjectSuffix) $(IntermediateDirectory)/test_includes_TimeConstraint.cpp$(ObjectSuffix) $(IntermediateDirectory)/test_includes_XmlTestReporter.cpp$(ObjectSuffix) $(IntermediateDirectory)/entity_testAFTime.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d ".build-debug\arduino_fuoco" $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

".build-debug\arduino_fuoco":
	@$(MakeDirCommand) ".build-debug"
	@echo stam > ".build-debug\arduino_fuoco"




$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "Release"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/dev/arduino-fuoco/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) "main.cpp"

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


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) Release/*$(ObjectSuffix)
	$(RM) Release/*$(DependSuffix)
	$(RM) $(OutputFile)
	$(RM) $(OutputFile).exe
	$(RM) ".build-debug/unit_testing"

