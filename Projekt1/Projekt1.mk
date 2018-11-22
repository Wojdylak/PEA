##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Release
ProjectName            :=Projekt1
ConfigurationName      :=Release
WorkspacePath          :=C:/Users/Admin/Documents/semest5/ProjektowanieEfektywnych/Projekty
ProjectPath            :=C:/Users/Admin/Documents/semest5/ProjektowanieEfektywnych/Projekty/Projekt1
IntermediateDirectory  :=./Release
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Admin
Date                   :=22/11/2018
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
ObjectsFileList        :="Projekt1.txt"
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
Objects0=$(IntermediateDirectory)/matrixCost.cpp$(ObjectSuffix) $(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/DynamicBitmask.cpp$(ObjectSuffix) $(IntermediateDirectory)/BranchAndBound.cpp$(ObjectSuffix) $(IntermediateDirectory)/BruteForce.cpp$(ObjectSuffix) 



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
$(IntermediateDirectory)/matrixCost.cpp$(ObjectSuffix): matrixCost.cpp $(IntermediateDirectory)/matrixCost.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Admin/Documents/semest5/ProjektowanieEfektywnych/Projekty/Projekt1/matrixCost.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/matrixCost.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/matrixCost.cpp$(DependSuffix): matrixCost.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/matrixCost.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/matrixCost.cpp$(DependSuffix) -MM matrixCost.cpp

$(IntermediateDirectory)/matrixCost.cpp$(PreprocessSuffix): matrixCost.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/matrixCost.cpp$(PreprocessSuffix) matrixCost.cpp

$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Admin/Documents/semest5/ProjektowanieEfektywnych/Projekty/Projekt1/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/DynamicBitmask.cpp$(ObjectSuffix): DynamicBitmask.cpp $(IntermediateDirectory)/DynamicBitmask.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Admin/Documents/semest5/ProjektowanieEfektywnych/Projekty/Projekt1/DynamicBitmask.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/DynamicBitmask.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/DynamicBitmask.cpp$(DependSuffix): DynamicBitmask.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/DynamicBitmask.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/DynamicBitmask.cpp$(DependSuffix) -MM DynamicBitmask.cpp

$(IntermediateDirectory)/DynamicBitmask.cpp$(PreprocessSuffix): DynamicBitmask.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/DynamicBitmask.cpp$(PreprocessSuffix) DynamicBitmask.cpp

$(IntermediateDirectory)/BranchAndBound.cpp$(ObjectSuffix): BranchAndBound.cpp $(IntermediateDirectory)/BranchAndBound.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Admin/Documents/semest5/ProjektowanieEfektywnych/Projekty/Projekt1/BranchAndBound.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/BranchAndBound.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/BranchAndBound.cpp$(DependSuffix): BranchAndBound.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/BranchAndBound.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/BranchAndBound.cpp$(DependSuffix) -MM BranchAndBound.cpp

$(IntermediateDirectory)/BranchAndBound.cpp$(PreprocessSuffix): BranchAndBound.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/BranchAndBound.cpp$(PreprocessSuffix) BranchAndBound.cpp

$(IntermediateDirectory)/BruteForce.cpp$(ObjectSuffix): BruteForce.cpp $(IntermediateDirectory)/BruteForce.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Admin/Documents/semest5/ProjektowanieEfektywnych/Projekty/Projekt1/BruteForce.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/BruteForce.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/BruteForce.cpp$(DependSuffix): BruteForce.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/BruteForce.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/BruteForce.cpp$(DependSuffix) -MM BruteForce.cpp

$(IntermediateDirectory)/BruteForce.cpp$(PreprocessSuffix): BruteForce.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/BruteForce.cpp$(PreprocessSuffix) BruteForce.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Release/


