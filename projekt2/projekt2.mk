##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Release
ProjectName            :=projekt2
ConfigurationName      :=Release
WorkspacePath          :=C:/Users/Admin/Documents/semest5/ProjektowanieEfektywnych/Projekty
ProjectPath            :=C:/Users/Admin/Documents/semest5/ProjektowanieEfektywnych/Projekty/projekt2
IntermediateDirectory  :=./Release
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Admin
Date                   :=07/12/2018
CodeLitePath           :=D:/Programy/CodeLite
LinkerName             :=D:/Programy/TDM-GCC/bin/g++.exe
SharedObjectLinkerName :=D:/Programy/TDM-GCC/bin/g++.exe -shared -fPIC
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
Preprocessors          :=$(PreprocessorSwitch)NDEBUG 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="projekt2.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=D:/Programy/TDM-GCC/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := D:/Programy/TDM-GCC/bin/ar.exe rcu
CXX      := D:/Programy/TDM-GCC/bin/g++.exe
CC       := D:/Programy/TDM-GCC/bin/gcc.exe
CXXFLAGS :=  -O2 -std=c++11 -Wall $(Preprocessors)
CFLAGS   :=  -O2 -std=c++11 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := D:/Programy/TDM-GCC/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=D:\Programy\CodeLite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/matrixCost.cpp$(ObjectSuffix) $(IntermediateDirectory)/TabuSearch.cpp$(ObjectSuffix) $(IntermediateDirectory)/SimulatedAnnealing.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Release"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Release"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Admin/Documents/semest5/ProjektowanieEfektywnych/Projekty/projekt2/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/matrixCost.cpp$(ObjectSuffix): matrixCost.cpp $(IntermediateDirectory)/matrixCost.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Admin/Documents/semest5/ProjektowanieEfektywnych/Projekty/projekt2/matrixCost.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/matrixCost.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/matrixCost.cpp$(DependSuffix): matrixCost.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/matrixCost.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/matrixCost.cpp$(DependSuffix) -MM matrixCost.cpp

$(IntermediateDirectory)/matrixCost.cpp$(PreprocessSuffix): matrixCost.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/matrixCost.cpp$(PreprocessSuffix) matrixCost.cpp

$(IntermediateDirectory)/TabuSearch.cpp$(ObjectSuffix): TabuSearch.cpp $(IntermediateDirectory)/TabuSearch.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Admin/Documents/semest5/ProjektowanieEfektywnych/Projekty/projekt2/TabuSearch.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/TabuSearch.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/TabuSearch.cpp$(DependSuffix): TabuSearch.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/TabuSearch.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/TabuSearch.cpp$(DependSuffix) -MM TabuSearch.cpp

$(IntermediateDirectory)/TabuSearch.cpp$(PreprocessSuffix): TabuSearch.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/TabuSearch.cpp$(PreprocessSuffix) TabuSearch.cpp

$(IntermediateDirectory)/SimulatedAnnealing.cpp$(ObjectSuffix): SimulatedAnnealing.cpp $(IntermediateDirectory)/SimulatedAnnealing.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Admin/Documents/semest5/ProjektowanieEfektywnych/Projekty/projekt2/SimulatedAnnealing.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/SimulatedAnnealing.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/SimulatedAnnealing.cpp$(DependSuffix): SimulatedAnnealing.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/SimulatedAnnealing.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/SimulatedAnnealing.cpp$(DependSuffix) -MM SimulatedAnnealing.cpp

$(IntermediateDirectory)/SimulatedAnnealing.cpp$(PreprocessSuffix): SimulatedAnnealing.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/SimulatedAnnealing.cpp$(PreprocessSuffix) SimulatedAnnealing.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Release/


