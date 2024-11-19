// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dInevisdImilnedIfilesdIapellotdIGRAMSdIGramsSimmIworkdIGramsDataObjdIDictionary
#define R__NO_DEPRECATION

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "ROOT/RConfig.hxx"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// Header files passed as explicit arguments
#include "/nevis/milne/files/apellot/GRAMS/GramsSim/GramsDataObj/include/ElectronClusters.h"
#include "/nevis/milne/files/apellot/GRAMS/GramsSim/GramsDataObj/include/EventID.h"
#include "/nevis/milne/files/apellot/GRAMS/GramsSim/GramsDataObj/include/MCLArHits.h"
#include "/nevis/milne/files/apellot/GRAMS/GramsSim/GramsDataObj/include/MCScintHits.h"
#include "/nevis/milne/files/apellot/GRAMS/GramsSim/GramsDataObj/include/MCTrackList.h"
#include "/nevis/milne/files/apellot/GRAMS/GramsSim/GramsDataObj/include/ReadoutID.h"
#include "/nevis/milne/files/apellot/GRAMS/GramsSim/GramsDataObj/include/ReadoutMap.h"
#include "/nevis/milne/files/apellot/GRAMS/GramsSim/GramsDataObj/include/ReadoutWaveforms.h"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace ROOT {
   static TClass *tuplelEintcOintcOintgR_Dictionary();
   static void tuplelEintcOintcOintgR_TClassManip(TClass*);
   static void *new_tuplelEintcOintcOintgR(void *p = nullptr);
   static void *newArray_tuplelEintcOintcOintgR(Long_t size, void *p);
   static void delete_tuplelEintcOintcOintgR(void *p);
   static void deleteArray_tuplelEintcOintcOintgR(void *p);
   static void destruct_tuplelEintcOintcOintgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::tuple<int,int,int>*)
   {
      ::tuple<int,int,int> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::tuple<int,int,int>));
      static ::ROOT::TGenericClassInfo 
         instance("tuple<int,int,int>", "tuple", 609,
                  typeid(::tuple<int,int,int>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &tuplelEintcOintcOintgR_Dictionary, isa_proxy, 4,
                  sizeof(::tuple<int,int,int>) );
      instance.SetNew(&new_tuplelEintcOintcOintgR);
      instance.SetNewArray(&newArray_tuplelEintcOintcOintgR);
      instance.SetDelete(&delete_tuplelEintcOintcOintgR);
      instance.SetDeleteArray(&deleteArray_tuplelEintcOintcOintgR);
      instance.SetDestructor(&destruct_tuplelEintcOintcOintgR);

      ::ROOT::AddClassAlternate("tuple<int,int,int>","std::tuple<int, int, int>");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::tuple<int,int,int>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *tuplelEintcOintcOintgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::tuple<int,int,int>*>(nullptr))->GetClass();
      tuplelEintcOintcOintgR_TClassManip(theClass);
   return theClass;
   }

   static void tuplelEintcOintcOintgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *tuplelEintcOintgR_Dictionary();
   static void tuplelEintcOintgR_TClassManip(TClass*);
   static void *new_tuplelEintcOintgR(void *p = nullptr);
   static void *newArray_tuplelEintcOintgR(Long_t size, void *p);
   static void delete_tuplelEintcOintgR(void *p);
   static void deleteArray_tuplelEintcOintgR(void *p);
   static void destruct_tuplelEintcOintgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::tuple<int,int>*)
   {
      ::tuple<int,int> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::tuple<int,int>));
      static ::ROOT::TGenericClassInfo 
         instance("tuple<int,int>", "tuple", 981,
                  typeid(::tuple<int,int>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &tuplelEintcOintgR_Dictionary, isa_proxy, 4,
                  sizeof(::tuple<int,int>) );
      instance.SetNew(&new_tuplelEintcOintgR);
      instance.SetNewArray(&newArray_tuplelEintcOintgR);
      instance.SetDelete(&delete_tuplelEintcOintgR);
      instance.SetDeleteArray(&deleteArray_tuplelEintcOintgR);
      instance.SetDestructor(&destruct_tuplelEintcOintgR);

      ::ROOT::AddClassAlternate("tuple<int,int>","std::tuple<int, int>");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::tuple<int,int>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *tuplelEintcOintgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::tuple<int,int>*>(nullptr))->GetClass();
      tuplelEintcOintgR_TClassManip(theClass);
   return theClass;
   }

   static void tuplelEintcOintgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *gramscLcLElectronCluster_Dictionary();
   static void gramscLcLElectronCluster_TClassManip(TClass*);
   static void *new_gramscLcLElectronCluster(void *p = nullptr);
   static void *newArray_gramscLcLElectronCluster(Long_t size, void *p);
   static void delete_gramscLcLElectronCluster(void *p);
   static void deleteArray_gramscLcLElectronCluster(void *p);
   static void destruct_gramscLcLElectronCluster(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::grams::ElectronCluster*)
   {
      ::grams::ElectronCluster *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::grams::ElectronCluster));
      static ::ROOT::TGenericClassInfo 
         instance("grams::ElectronCluster", "", 20,
                  typeid(::grams::ElectronCluster), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &gramscLcLElectronCluster_Dictionary, isa_proxy, 4,
                  sizeof(::grams::ElectronCluster) );
      instance.SetNew(&new_gramscLcLElectronCluster);
      instance.SetNewArray(&newArray_gramscLcLElectronCluster);
      instance.SetDelete(&delete_gramscLcLElectronCluster);
      instance.SetDeleteArray(&deleteArray_gramscLcLElectronCluster);
      instance.SetDestructor(&destruct_gramscLcLElectronCluster);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::grams::ElectronCluster*)
   {
      return GenerateInitInstanceLocal(static_cast<::grams::ElectronCluster*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::grams::ElectronCluster*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *gramscLcLElectronCluster_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::grams::ElectronCluster*>(nullptr))->GetClass();
      gramscLcLElectronCluster_TClassManip(theClass);
   return theClass;
   }

   static void gramscLcLElectronCluster_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *gramscLcLEventID_Dictionary();
   static void gramscLcLEventID_TClassManip(TClass*);
   static void *new_gramscLcLEventID(void *p = nullptr);
   static void *newArray_gramscLcLEventID(Long_t size, void *p);
   static void delete_gramscLcLEventID(void *p);
   static void deleteArray_gramscLcLEventID(void *p);
   static void destruct_gramscLcLEventID(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::grams::EventID*)
   {
      ::grams::EventID *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::grams::EventID));
      static ::ROOT::TGenericClassInfo 
         instance("grams::EventID", "", 33,
                  typeid(::grams::EventID), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &gramscLcLEventID_Dictionary, isa_proxy, 4,
                  sizeof(::grams::EventID) );
      instance.SetNew(&new_gramscLcLEventID);
      instance.SetNewArray(&newArray_gramscLcLEventID);
      instance.SetDelete(&delete_gramscLcLEventID);
      instance.SetDeleteArray(&deleteArray_gramscLcLEventID);
      instance.SetDestructor(&destruct_gramscLcLEventID);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::grams::EventID*)
   {
      return GenerateInitInstanceLocal(static_cast<::grams::EventID*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::grams::EventID*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *gramscLcLEventID_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::grams::EventID*>(nullptr))->GetClass();
      gramscLcLEventID_TClassManip(theClass);
   return theClass;
   }

   static void gramscLcLEventID_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *gramscLcLMCLArHit_Dictionary();
   static void gramscLcLMCLArHit_TClassManip(TClass*);
   static void *new_gramscLcLMCLArHit(void *p = nullptr);
   static void *newArray_gramscLcLMCLArHit(Long_t size, void *p);
   static void delete_gramscLcLMCLArHit(void *p);
   static void deleteArray_gramscLcLMCLArHit(void *p);
   static void destruct_gramscLcLMCLArHit(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::grams::MCLArHit*)
   {
      ::grams::MCLArHit *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::grams::MCLArHit));
      static ::ROOT::TGenericClassInfo 
         instance("grams::MCLArHit", "", 20,
                  typeid(::grams::MCLArHit), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &gramscLcLMCLArHit_Dictionary, isa_proxy, 4,
                  sizeof(::grams::MCLArHit) );
      instance.SetNew(&new_gramscLcLMCLArHit);
      instance.SetNewArray(&newArray_gramscLcLMCLArHit);
      instance.SetDelete(&delete_gramscLcLMCLArHit);
      instance.SetDeleteArray(&deleteArray_gramscLcLMCLArHit);
      instance.SetDestructor(&destruct_gramscLcLMCLArHit);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::grams::MCLArHit*)
   {
      return GenerateInitInstanceLocal(static_cast<::grams::MCLArHit*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::grams::MCLArHit*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *gramscLcLMCLArHit_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::grams::MCLArHit*>(nullptr))->GetClass();
      gramscLcLMCLArHit_TClassManip(theClass);
   return theClass;
   }

   static void gramscLcLMCLArHit_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *gramscLcLMCScintHit_Dictionary();
   static void gramscLcLMCScintHit_TClassManip(TClass*);
   static void *new_gramscLcLMCScintHit(void *p = nullptr);
   static void *newArray_gramscLcLMCScintHit(Long_t size, void *p);
   static void delete_gramscLcLMCScintHit(void *p);
   static void deleteArray_gramscLcLMCScintHit(void *p);
   static void destruct_gramscLcLMCScintHit(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::grams::MCScintHit*)
   {
      ::grams::MCScintHit *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::grams::MCScintHit));
      static ::ROOT::TGenericClassInfo 
         instance("grams::MCScintHit", "", 19,
                  typeid(::grams::MCScintHit), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &gramscLcLMCScintHit_Dictionary, isa_proxy, 4,
                  sizeof(::grams::MCScintHit) );
      instance.SetNew(&new_gramscLcLMCScintHit);
      instance.SetNewArray(&newArray_gramscLcLMCScintHit);
      instance.SetDelete(&delete_gramscLcLMCScintHit);
      instance.SetDeleteArray(&deleteArray_gramscLcLMCScintHit);
      instance.SetDestructor(&destruct_gramscLcLMCScintHit);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::grams::MCScintHit*)
   {
      return GenerateInitInstanceLocal(static_cast<::grams::MCScintHit*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::grams::MCScintHit*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *gramscLcLMCScintHit_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::grams::MCScintHit*>(nullptr))->GetClass();
      gramscLcLMCScintHit_TClassManip(theClass);
   return theClass;
   }

   static void gramscLcLMCScintHit_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *gramscLcLMCTrajectoryPoint_Dictionary();
   static void gramscLcLMCTrajectoryPoint_TClassManip(TClass*);
   static void *new_gramscLcLMCTrajectoryPoint(void *p = nullptr);
   static void *newArray_gramscLcLMCTrajectoryPoint(Long_t size, void *p);
   static void delete_gramscLcLMCTrajectoryPoint(void *p);
   static void deleteArray_gramscLcLMCTrajectoryPoint(void *p);
   static void destruct_gramscLcLMCTrajectoryPoint(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::grams::MCTrajectoryPoint*)
   {
      ::grams::MCTrajectoryPoint *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::grams::MCTrajectoryPoint));
      static ::ROOT::TGenericClassInfo 
         instance("grams::MCTrajectoryPoint", "", 24,
                  typeid(::grams::MCTrajectoryPoint), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &gramscLcLMCTrajectoryPoint_Dictionary, isa_proxy, 4,
                  sizeof(::grams::MCTrajectoryPoint) );
      instance.SetNew(&new_gramscLcLMCTrajectoryPoint);
      instance.SetNewArray(&newArray_gramscLcLMCTrajectoryPoint);
      instance.SetDelete(&delete_gramscLcLMCTrajectoryPoint);
      instance.SetDeleteArray(&deleteArray_gramscLcLMCTrajectoryPoint);
      instance.SetDestructor(&destruct_gramscLcLMCTrajectoryPoint);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::grams::MCTrajectoryPoint*)
   {
      return GenerateInitInstanceLocal(static_cast<::grams::MCTrajectoryPoint*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::grams::MCTrajectoryPoint*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *gramscLcLMCTrajectoryPoint_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::grams::MCTrajectoryPoint*>(nullptr))->GetClass();
      gramscLcLMCTrajectoryPoint_TClassManip(theClass);
   return theClass;
   }

   static void gramscLcLMCTrajectoryPoint_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *gramscLcLMCTrack_Dictionary();
   static void gramscLcLMCTrack_TClassManip(TClass*);
   static void *new_gramscLcLMCTrack(void *p = nullptr);
   static void *newArray_gramscLcLMCTrack(Long_t size, void *p);
   static void delete_gramscLcLMCTrack(void *p);
   static void deleteArray_gramscLcLMCTrack(void *p);
   static void destruct_gramscLcLMCTrack(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::grams::MCTrack*)
   {
      ::grams::MCTrack *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::grams::MCTrack));
      static ::ROOT::TGenericClassInfo 
         instance("grams::MCTrack", "", 64,
                  typeid(::grams::MCTrack), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &gramscLcLMCTrack_Dictionary, isa_proxy, 4,
                  sizeof(::grams::MCTrack) );
      instance.SetNew(&new_gramscLcLMCTrack);
      instance.SetNewArray(&newArray_gramscLcLMCTrack);
      instance.SetDelete(&delete_gramscLcLMCTrack);
      instance.SetDeleteArray(&deleteArray_gramscLcLMCTrack);
      instance.SetDestructor(&destruct_gramscLcLMCTrack);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::grams::MCTrack*)
   {
      return GenerateInitInstanceLocal(static_cast<::grams::MCTrack*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::grams::MCTrack*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *gramscLcLMCTrack_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::grams::MCTrack*>(nullptr))->GetClass();
      gramscLcLMCTrack_TClassManip(theClass);
   return theClass;
   }

   static void gramscLcLMCTrack_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *gramscLcLReadoutID_Dictionary();
   static void gramscLcLReadoutID_TClassManip(TClass*);
   static void *new_gramscLcLReadoutID(void *p = nullptr);
   static void *newArray_gramscLcLReadoutID(Long_t size, void *p);
   static void delete_gramscLcLReadoutID(void *p);
   static void deleteArray_gramscLcLReadoutID(void *p);
   static void destruct_gramscLcLReadoutID(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::grams::ReadoutID*)
   {
      ::grams::ReadoutID *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::grams::ReadoutID));
      static ::ROOT::TGenericClassInfo 
         instance("grams::ReadoutID", "", 27,
                  typeid(::grams::ReadoutID), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &gramscLcLReadoutID_Dictionary, isa_proxy, 4,
                  sizeof(::grams::ReadoutID) );
      instance.SetNew(&new_gramscLcLReadoutID);
      instance.SetNewArray(&newArray_gramscLcLReadoutID);
      instance.SetDelete(&delete_gramscLcLReadoutID);
      instance.SetDeleteArray(&deleteArray_gramscLcLReadoutID);
      instance.SetDestructor(&destruct_gramscLcLReadoutID);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::grams::ReadoutID*)
   {
      return GenerateInitInstanceLocal(static_cast<::grams::ReadoutID*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::grams::ReadoutID*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *gramscLcLReadoutID_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::grams::ReadoutID*>(nullptr))->GetClass();
      gramscLcLReadoutID_TClassManip(theClass);
   return theClass;
   }

   static void gramscLcLReadoutID_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *gramscLcLReadoutWaveform_Dictionary();
   static void gramscLcLReadoutWaveform_TClassManip(TClass*);
   static void *new_gramscLcLReadoutWaveform(void *p = nullptr);
   static void *newArray_gramscLcLReadoutWaveform(Long_t size, void *p);
   static void delete_gramscLcLReadoutWaveform(void *p);
   static void deleteArray_gramscLcLReadoutWaveform(void *p);
   static void destruct_gramscLcLReadoutWaveform(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::grams::ReadoutWaveform*)
   {
      ::grams::ReadoutWaveform *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::grams::ReadoutWaveform));
      static ::ROOT::TGenericClassInfo 
         instance("grams::ReadoutWaveform", "", 19,
                  typeid(::grams::ReadoutWaveform), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &gramscLcLReadoutWaveform_Dictionary, isa_proxy, 4,
                  sizeof(::grams::ReadoutWaveform) );
      instance.SetNew(&new_gramscLcLReadoutWaveform);
      instance.SetNewArray(&newArray_gramscLcLReadoutWaveform);
      instance.SetDelete(&delete_gramscLcLReadoutWaveform);
      instance.SetDeleteArray(&deleteArray_gramscLcLReadoutWaveform);
      instance.SetDestructor(&destruct_gramscLcLReadoutWaveform);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::grams::ReadoutWaveform*)
   {
      return GenerateInitInstanceLocal(static_cast<::grams::ReadoutWaveform*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::grams::ReadoutWaveform*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *gramscLcLReadoutWaveform_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::grams::ReadoutWaveform*>(nullptr))->GetClass();
      gramscLcLReadoutWaveform_TClassManip(theClass);
   return theClass;
   }

   static void gramscLcLReadoutWaveform_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_tuplelEintcOintcOintgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::tuple<int,int,int> : new ::tuple<int,int,int>;
   }
   static void *newArray_tuplelEintcOintcOintgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::tuple<int,int,int>[nElements] : new ::tuple<int,int,int>[nElements];
   }
   // Wrapper around operator delete
   static void delete_tuplelEintcOintcOintgR(void *p) {
      delete (static_cast<::tuple<int,int,int>*>(p));
   }
   static void deleteArray_tuplelEintcOintcOintgR(void *p) {
      delete [] (static_cast<::tuple<int,int,int>*>(p));
   }
   static void destruct_tuplelEintcOintcOintgR(void *p) {
      typedef ::tuple<int,int,int> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::tuple<int,int,int>

namespace ROOT {
   // Wrappers around operator new
   static void *new_tuplelEintcOintgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::tuple<int,int> : new ::tuple<int,int>;
   }
   static void *newArray_tuplelEintcOintgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::tuple<int,int>[nElements] : new ::tuple<int,int>[nElements];
   }
   // Wrapper around operator delete
   static void delete_tuplelEintcOintgR(void *p) {
      delete (static_cast<::tuple<int,int>*>(p));
   }
   static void deleteArray_tuplelEintcOintgR(void *p) {
      delete [] (static_cast<::tuple<int,int>*>(p));
   }
   static void destruct_tuplelEintcOintgR(void *p) {
      typedef ::tuple<int,int> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::tuple<int,int>

namespace ROOT {
   // Wrappers around operator new
   static void *new_gramscLcLElectronCluster(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::grams::ElectronCluster : new ::grams::ElectronCluster;
   }
   static void *newArray_gramscLcLElectronCluster(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::grams::ElectronCluster[nElements] : new ::grams::ElectronCluster[nElements];
   }
   // Wrapper around operator delete
   static void delete_gramscLcLElectronCluster(void *p) {
      delete (static_cast<::grams::ElectronCluster*>(p));
   }
   static void deleteArray_gramscLcLElectronCluster(void *p) {
      delete [] (static_cast<::grams::ElectronCluster*>(p));
   }
   static void destruct_gramscLcLElectronCluster(void *p) {
      typedef ::grams::ElectronCluster current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::grams::ElectronCluster

namespace ROOT {
   // Wrappers around operator new
   static void *new_gramscLcLEventID(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::grams::EventID : new ::grams::EventID;
   }
   static void *newArray_gramscLcLEventID(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::grams::EventID[nElements] : new ::grams::EventID[nElements];
   }
   // Wrapper around operator delete
   static void delete_gramscLcLEventID(void *p) {
      delete (static_cast<::grams::EventID*>(p));
   }
   static void deleteArray_gramscLcLEventID(void *p) {
      delete [] (static_cast<::grams::EventID*>(p));
   }
   static void destruct_gramscLcLEventID(void *p) {
      typedef ::grams::EventID current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::grams::EventID

namespace ROOT {
   // Wrappers around operator new
   static void *new_gramscLcLMCLArHit(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::grams::MCLArHit : new ::grams::MCLArHit;
   }
   static void *newArray_gramscLcLMCLArHit(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::grams::MCLArHit[nElements] : new ::grams::MCLArHit[nElements];
   }
   // Wrapper around operator delete
   static void delete_gramscLcLMCLArHit(void *p) {
      delete (static_cast<::grams::MCLArHit*>(p));
   }
   static void deleteArray_gramscLcLMCLArHit(void *p) {
      delete [] (static_cast<::grams::MCLArHit*>(p));
   }
   static void destruct_gramscLcLMCLArHit(void *p) {
      typedef ::grams::MCLArHit current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::grams::MCLArHit

namespace ROOT {
   // Wrappers around operator new
   static void *new_gramscLcLMCScintHit(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::grams::MCScintHit : new ::grams::MCScintHit;
   }
   static void *newArray_gramscLcLMCScintHit(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::grams::MCScintHit[nElements] : new ::grams::MCScintHit[nElements];
   }
   // Wrapper around operator delete
   static void delete_gramscLcLMCScintHit(void *p) {
      delete (static_cast<::grams::MCScintHit*>(p));
   }
   static void deleteArray_gramscLcLMCScintHit(void *p) {
      delete [] (static_cast<::grams::MCScintHit*>(p));
   }
   static void destruct_gramscLcLMCScintHit(void *p) {
      typedef ::grams::MCScintHit current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::grams::MCScintHit

namespace ROOT {
   // Wrappers around operator new
   static void *new_gramscLcLMCTrajectoryPoint(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::grams::MCTrajectoryPoint : new ::grams::MCTrajectoryPoint;
   }
   static void *newArray_gramscLcLMCTrajectoryPoint(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::grams::MCTrajectoryPoint[nElements] : new ::grams::MCTrajectoryPoint[nElements];
   }
   // Wrapper around operator delete
   static void delete_gramscLcLMCTrajectoryPoint(void *p) {
      delete (static_cast<::grams::MCTrajectoryPoint*>(p));
   }
   static void deleteArray_gramscLcLMCTrajectoryPoint(void *p) {
      delete [] (static_cast<::grams::MCTrajectoryPoint*>(p));
   }
   static void destruct_gramscLcLMCTrajectoryPoint(void *p) {
      typedef ::grams::MCTrajectoryPoint current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::grams::MCTrajectoryPoint

namespace ROOT {
   // Wrappers around operator new
   static void *new_gramscLcLMCTrack(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::grams::MCTrack : new ::grams::MCTrack;
   }
   static void *newArray_gramscLcLMCTrack(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::grams::MCTrack[nElements] : new ::grams::MCTrack[nElements];
   }
   // Wrapper around operator delete
   static void delete_gramscLcLMCTrack(void *p) {
      delete (static_cast<::grams::MCTrack*>(p));
   }
   static void deleteArray_gramscLcLMCTrack(void *p) {
      delete [] (static_cast<::grams::MCTrack*>(p));
   }
   static void destruct_gramscLcLMCTrack(void *p) {
      typedef ::grams::MCTrack current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::grams::MCTrack

namespace ROOT {
   // Wrappers around operator new
   static void *new_gramscLcLReadoutID(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::grams::ReadoutID : new ::grams::ReadoutID;
   }
   static void *newArray_gramscLcLReadoutID(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::grams::ReadoutID[nElements] : new ::grams::ReadoutID[nElements];
   }
   // Wrapper around operator delete
   static void delete_gramscLcLReadoutID(void *p) {
      delete (static_cast<::grams::ReadoutID*>(p));
   }
   static void deleteArray_gramscLcLReadoutID(void *p) {
      delete [] (static_cast<::grams::ReadoutID*>(p));
   }
   static void destruct_gramscLcLReadoutID(void *p) {
      typedef ::grams::ReadoutID current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::grams::ReadoutID

namespace ROOT {
   // Wrappers around operator new
   static void *new_gramscLcLReadoutWaveform(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::grams::ReadoutWaveform : new ::grams::ReadoutWaveform;
   }
   static void *newArray_gramscLcLReadoutWaveform(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::grams::ReadoutWaveform[nElements] : new ::grams::ReadoutWaveform[nElements];
   }
   // Wrapper around operator delete
   static void delete_gramscLcLReadoutWaveform(void *p) {
      delete (static_cast<::grams::ReadoutWaveform*>(p));
   }
   static void deleteArray_gramscLcLReadoutWaveform(void *p) {
      delete [] (static_cast<::grams::ReadoutWaveform*>(p));
   }
   static void destruct_gramscLcLReadoutWaveform(void *p) {
      typedef ::grams::ReadoutWaveform current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::grams::ReadoutWaveform

namespace ROOT {
   static TClass *vectorlEintgR_Dictionary();
   static void vectorlEintgR_TClassManip(TClass*);
   static void *new_vectorlEintgR(void *p = nullptr);
   static void *newArray_vectorlEintgR(Long_t size, void *p);
   static void delete_vectorlEintgR(void *p);
   static void deleteArray_vectorlEintgR(void *p);
   static void destruct_vectorlEintgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<int>*)
   {
      vector<int> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<int>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<int>", -2, "vector", 423,
                  typeid(vector<int>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEintgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<int>) );
      instance.SetNew(&new_vectorlEintgR);
      instance.SetNewArray(&newArray_vectorlEintgR);
      instance.SetDelete(&delete_vectorlEintgR);
      instance.SetDeleteArray(&deleteArray_vectorlEintgR);
      instance.SetDestructor(&destruct_vectorlEintgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<int> >()));

      ::ROOT::AddClassAlternate("vector<int>","std::vector<int, std::allocator<int> >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<int>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEintgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<int>*>(nullptr))->GetClass();
      vectorlEintgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEintgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEintgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<int> : new vector<int>;
   }
   static void *newArray_vectorlEintgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<int>[nElements] : new vector<int>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEintgR(void *p) {
      delete (static_cast<vector<int>*>(p));
   }
   static void deleteArray_vectorlEintgR(void *p) {
      delete [] (static_cast<vector<int>*>(p));
   }
   static void destruct_vectorlEintgR(void *p) {
      typedef vector<int> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<int>

namespace ROOT {
   static TClass *vectorlEgramscLcLMCTrajectoryPointgR_Dictionary();
   static void vectorlEgramscLcLMCTrajectoryPointgR_TClassManip(TClass*);
   static void *new_vectorlEgramscLcLMCTrajectoryPointgR(void *p = nullptr);
   static void *newArray_vectorlEgramscLcLMCTrajectoryPointgR(Long_t size, void *p);
   static void delete_vectorlEgramscLcLMCTrajectoryPointgR(void *p);
   static void deleteArray_vectorlEgramscLcLMCTrajectoryPointgR(void *p);
   static void destruct_vectorlEgramscLcLMCTrajectoryPointgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<grams::MCTrajectoryPoint>*)
   {
      vector<grams::MCTrajectoryPoint> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<grams::MCTrajectoryPoint>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<grams::MCTrajectoryPoint>", -2, "vector", 423,
                  typeid(vector<grams::MCTrajectoryPoint>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEgramscLcLMCTrajectoryPointgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<grams::MCTrajectoryPoint>) );
      instance.SetNew(&new_vectorlEgramscLcLMCTrajectoryPointgR);
      instance.SetNewArray(&newArray_vectorlEgramscLcLMCTrajectoryPointgR);
      instance.SetDelete(&delete_vectorlEgramscLcLMCTrajectoryPointgR);
      instance.SetDeleteArray(&deleteArray_vectorlEgramscLcLMCTrajectoryPointgR);
      instance.SetDestructor(&destruct_vectorlEgramscLcLMCTrajectoryPointgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<grams::MCTrajectoryPoint> >()));

      ::ROOT::AddClassAlternate("vector<grams::MCTrajectoryPoint>","std::vector<grams::MCTrajectoryPoint, std::allocator<grams::MCTrajectoryPoint> >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<grams::MCTrajectoryPoint>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEgramscLcLMCTrajectoryPointgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<grams::MCTrajectoryPoint>*>(nullptr))->GetClass();
      vectorlEgramscLcLMCTrajectoryPointgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEgramscLcLMCTrajectoryPointgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEgramscLcLMCTrajectoryPointgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<grams::MCTrajectoryPoint> : new vector<grams::MCTrajectoryPoint>;
   }
   static void *newArray_vectorlEgramscLcLMCTrajectoryPointgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<grams::MCTrajectoryPoint>[nElements] : new vector<grams::MCTrajectoryPoint>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEgramscLcLMCTrajectoryPointgR(void *p) {
      delete (static_cast<vector<grams::MCTrajectoryPoint>*>(p));
   }
   static void deleteArray_vectorlEgramscLcLMCTrajectoryPointgR(void *p) {
      delete [] (static_cast<vector<grams::MCTrajectoryPoint>*>(p));
   }
   static void destruct_vectorlEgramscLcLMCTrajectoryPointgR(void *p) {
      typedef vector<grams::MCTrajectoryPoint> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<grams::MCTrajectoryPoint>

namespace ROOT {
   static TClass *vectorlEdoublegR_Dictionary();
   static void vectorlEdoublegR_TClassManip(TClass*);
   static void *new_vectorlEdoublegR(void *p = nullptr);
   static void *newArray_vectorlEdoublegR(Long_t size, void *p);
   static void delete_vectorlEdoublegR(void *p);
   static void deleteArray_vectorlEdoublegR(void *p);
   static void destruct_vectorlEdoublegR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<double>*)
   {
      vector<double> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<double>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<double>", -2, "vector", 423,
                  typeid(vector<double>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEdoublegR_Dictionary, isa_proxy, 0,
                  sizeof(vector<double>) );
      instance.SetNew(&new_vectorlEdoublegR);
      instance.SetNewArray(&newArray_vectorlEdoublegR);
      instance.SetDelete(&delete_vectorlEdoublegR);
      instance.SetDeleteArray(&deleteArray_vectorlEdoublegR);
      instance.SetDestructor(&destruct_vectorlEdoublegR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<double> >()));

      ::ROOT::AddClassAlternate("vector<double>","std::vector<double, std::allocator<double> >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<double>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEdoublegR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<double>*>(nullptr))->GetClass();
      vectorlEdoublegR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEdoublegR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEdoublegR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<double> : new vector<double>;
   }
   static void *newArray_vectorlEdoublegR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<double>[nElements] : new vector<double>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEdoublegR(void *p) {
      delete (static_cast<vector<double>*>(p));
   }
   static void deleteArray_vectorlEdoublegR(void *p) {
      delete [] (static_cast<vector<double>*>(p));
   }
   static void destruct_vectorlEdoublegR(void *p) {
      typedef vector<double> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<double>

namespace ROOT {
   static TClass *setlEtuplelEintcOintcOintgRsPgR_Dictionary();
   static void setlEtuplelEintcOintcOintgRsPgR_TClassManip(TClass*);
   static void *new_setlEtuplelEintcOintcOintgRsPgR(void *p = nullptr);
   static void *newArray_setlEtuplelEintcOintcOintgRsPgR(Long_t size, void *p);
   static void delete_setlEtuplelEintcOintcOintgRsPgR(void *p);
   static void deleteArray_setlEtuplelEintcOintcOintgRsPgR(void *p);
   static void destruct_setlEtuplelEintcOintcOintgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const set<tuple<int,int,int> >*)
   {
      set<tuple<int,int,int> > *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(set<tuple<int,int,int> >));
      static ::ROOT::TGenericClassInfo 
         instance("set<tuple<int,int,int> >", -2, "set", 94,
                  typeid(set<tuple<int,int,int> >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &setlEtuplelEintcOintcOintgRsPgR_Dictionary, isa_proxy, 4,
                  sizeof(set<tuple<int,int,int> >) );
      instance.SetNew(&new_setlEtuplelEintcOintcOintgRsPgR);
      instance.SetNewArray(&newArray_setlEtuplelEintcOintcOintgRsPgR);
      instance.SetDelete(&delete_setlEtuplelEintcOintcOintgRsPgR);
      instance.SetDeleteArray(&deleteArray_setlEtuplelEintcOintcOintgRsPgR);
      instance.SetDestructor(&destruct_setlEtuplelEintcOintcOintgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Insert< set<tuple<int,int,int> > >()));

      ::ROOT::AddClassAlternate("set<tuple<int,int,int> >","std::set<std::tuple<int, int, int>, std::less<std::tuple<int, int, int> >, std::allocator<std::tuple<int, int, int> > >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const set<tuple<int,int,int> >*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *setlEtuplelEintcOintcOintgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const set<tuple<int,int,int> >*>(nullptr))->GetClass();
      setlEtuplelEintcOintcOintgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void setlEtuplelEintcOintcOintgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_setlEtuplelEintcOintcOintgRsPgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) set<tuple<int,int,int> > : new set<tuple<int,int,int> >;
   }
   static void *newArray_setlEtuplelEintcOintcOintgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) set<tuple<int,int,int> >[nElements] : new set<tuple<int,int,int> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_setlEtuplelEintcOintcOintgRsPgR(void *p) {
      delete (static_cast<set<tuple<int,int,int> >*>(p));
   }
   static void deleteArray_setlEtuplelEintcOintcOintgRsPgR(void *p) {
      delete [] (static_cast<set<tuple<int,int,int> >*>(p));
   }
   static void destruct_setlEtuplelEintcOintcOintgRsPgR(void *p) {
      typedef set<tuple<int,int,int> > current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class set<tuple<int,int,int> >

namespace ROOT {
   static TClass *setlEintgR_Dictionary();
   static void setlEintgR_TClassManip(TClass*);
   static void *new_setlEintgR(void *p = nullptr);
   static void *newArray_setlEintgR(Long_t size, void *p);
   static void delete_setlEintgR(void *p);
   static void deleteArray_setlEintgR(void *p);
   static void destruct_setlEintgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const set<int>*)
   {
      set<int> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(set<int>));
      static ::ROOT::TGenericClassInfo 
         instance("set<int>", -2, "set", 94,
                  typeid(set<int>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &setlEintgR_Dictionary, isa_proxy, 0,
                  sizeof(set<int>) );
      instance.SetNew(&new_setlEintgR);
      instance.SetNewArray(&newArray_setlEintgR);
      instance.SetDelete(&delete_setlEintgR);
      instance.SetDeleteArray(&deleteArray_setlEintgR);
      instance.SetDestructor(&destruct_setlEintgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Insert< set<int> >()));

      ::ROOT::AddClassAlternate("set<int>","std::set<int, std::less<int>, std::allocator<int> >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const set<int>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *setlEintgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const set<int>*>(nullptr))->GetClass();
      setlEintgR_TClassManip(theClass);
   return theClass;
   }

   static void setlEintgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_setlEintgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) set<int> : new set<int>;
   }
   static void *newArray_setlEintgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) set<int>[nElements] : new set<int>[nElements];
   }
   // Wrapper around operator delete
   static void delete_setlEintgR(void *p) {
      delete (static_cast<set<int>*>(p));
   }
   static void deleteArray_setlEintgR(void *p) {
      delete [] (static_cast<set<int>*>(p));
   }
   static void destruct_setlEintgR(void *p) {
      typedef set<int> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class set<int>

namespace ROOT {
   static TClass *maplEtuplelEintcOintgRcOgramscLcLMCScintHitgR_Dictionary();
   static void maplEtuplelEintcOintgRcOgramscLcLMCScintHitgR_TClassManip(TClass*);
   static void *new_maplEtuplelEintcOintgRcOgramscLcLMCScintHitgR(void *p = nullptr);
   static void *newArray_maplEtuplelEintcOintgRcOgramscLcLMCScintHitgR(Long_t size, void *p);
   static void delete_maplEtuplelEintcOintgRcOgramscLcLMCScintHitgR(void *p);
   static void deleteArray_maplEtuplelEintcOintgRcOgramscLcLMCScintHitgR(void *p);
   static void destruct_maplEtuplelEintcOintgRcOgramscLcLMCScintHitgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<tuple<int,int>,grams::MCScintHit>*)
   {
      map<tuple<int,int>,grams::MCScintHit> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<tuple<int,int>,grams::MCScintHit>));
      static ::ROOT::TGenericClassInfo 
         instance("map<tuple<int,int>,grams::MCScintHit>", -2, "map", 100,
                  typeid(map<tuple<int,int>,grams::MCScintHit>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &maplEtuplelEintcOintgRcOgramscLcLMCScintHitgR_Dictionary, isa_proxy, 4,
                  sizeof(map<tuple<int,int>,grams::MCScintHit>) );
      instance.SetNew(&new_maplEtuplelEintcOintgRcOgramscLcLMCScintHitgR);
      instance.SetNewArray(&newArray_maplEtuplelEintcOintgRcOgramscLcLMCScintHitgR);
      instance.SetDelete(&delete_maplEtuplelEintcOintgRcOgramscLcLMCScintHitgR);
      instance.SetDeleteArray(&deleteArray_maplEtuplelEintcOintgRcOgramscLcLMCScintHitgR);
      instance.SetDestructor(&destruct_maplEtuplelEintcOintgRcOgramscLcLMCScintHitgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<tuple<int,int>,grams::MCScintHit> >()));

      ::ROOT::AddClassAlternate("map<tuple<int,int>,grams::MCScintHit>","std::map<std::tuple<int, int>, grams::MCScintHit, std::less<std::tuple<int, int> >, std::allocator<std::pair<std::tuple<int, int> const, grams::MCScintHit> > >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const map<tuple<int,int>,grams::MCScintHit>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEtuplelEintcOintgRcOgramscLcLMCScintHitgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const map<tuple<int,int>,grams::MCScintHit>*>(nullptr))->GetClass();
      maplEtuplelEintcOintgRcOgramscLcLMCScintHitgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEtuplelEintcOintgRcOgramscLcLMCScintHitgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEtuplelEintcOintgRcOgramscLcLMCScintHitgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<tuple<int,int>,grams::MCScintHit> : new map<tuple<int,int>,grams::MCScintHit>;
   }
   static void *newArray_maplEtuplelEintcOintgRcOgramscLcLMCScintHitgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<tuple<int,int>,grams::MCScintHit>[nElements] : new map<tuple<int,int>,grams::MCScintHit>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEtuplelEintcOintgRcOgramscLcLMCScintHitgR(void *p) {
      delete (static_cast<map<tuple<int,int>,grams::MCScintHit>*>(p));
   }
   static void deleteArray_maplEtuplelEintcOintgRcOgramscLcLMCScintHitgR(void *p) {
      delete [] (static_cast<map<tuple<int,int>,grams::MCScintHit>*>(p));
   }
   static void destruct_maplEtuplelEintcOintgRcOgramscLcLMCScintHitgR(void *p) {
      typedef map<tuple<int,int>,grams::MCScintHit> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class map<tuple<int,int>,grams::MCScintHit>

namespace ROOT {
   static TClass *maplEtuplelEintcOintgRcOgramscLcLMCLArHitgR_Dictionary();
   static void maplEtuplelEintcOintgRcOgramscLcLMCLArHitgR_TClassManip(TClass*);
   static void *new_maplEtuplelEintcOintgRcOgramscLcLMCLArHitgR(void *p = nullptr);
   static void *newArray_maplEtuplelEintcOintgRcOgramscLcLMCLArHitgR(Long_t size, void *p);
   static void delete_maplEtuplelEintcOintgRcOgramscLcLMCLArHitgR(void *p);
   static void deleteArray_maplEtuplelEintcOintgRcOgramscLcLMCLArHitgR(void *p);
   static void destruct_maplEtuplelEintcOintgRcOgramscLcLMCLArHitgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<tuple<int,int>,grams::MCLArHit>*)
   {
      map<tuple<int,int>,grams::MCLArHit> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<tuple<int,int>,grams::MCLArHit>));
      static ::ROOT::TGenericClassInfo 
         instance("map<tuple<int,int>,grams::MCLArHit>", -2, "map", 100,
                  typeid(map<tuple<int,int>,grams::MCLArHit>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &maplEtuplelEintcOintgRcOgramscLcLMCLArHitgR_Dictionary, isa_proxy, 4,
                  sizeof(map<tuple<int,int>,grams::MCLArHit>) );
      instance.SetNew(&new_maplEtuplelEintcOintgRcOgramscLcLMCLArHitgR);
      instance.SetNewArray(&newArray_maplEtuplelEintcOintgRcOgramscLcLMCLArHitgR);
      instance.SetDelete(&delete_maplEtuplelEintcOintgRcOgramscLcLMCLArHitgR);
      instance.SetDeleteArray(&deleteArray_maplEtuplelEintcOintgRcOgramscLcLMCLArHitgR);
      instance.SetDestructor(&destruct_maplEtuplelEintcOintgRcOgramscLcLMCLArHitgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<tuple<int,int>,grams::MCLArHit> >()));

      ::ROOT::AddClassAlternate("map<tuple<int,int>,grams::MCLArHit>","std::map<std::tuple<int, int>, grams::MCLArHit, std::less<std::tuple<int, int> >, std::allocator<std::pair<std::tuple<int, int> const, grams::MCLArHit> > >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const map<tuple<int,int>,grams::MCLArHit>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEtuplelEintcOintgRcOgramscLcLMCLArHitgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const map<tuple<int,int>,grams::MCLArHit>*>(nullptr))->GetClass();
      maplEtuplelEintcOintgRcOgramscLcLMCLArHitgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEtuplelEintcOintgRcOgramscLcLMCLArHitgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEtuplelEintcOintgRcOgramscLcLMCLArHitgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<tuple<int,int>,grams::MCLArHit> : new map<tuple<int,int>,grams::MCLArHit>;
   }
   static void *newArray_maplEtuplelEintcOintgRcOgramscLcLMCLArHitgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<tuple<int,int>,grams::MCLArHit>[nElements] : new map<tuple<int,int>,grams::MCLArHit>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEtuplelEintcOintgRcOgramscLcLMCLArHitgR(void *p) {
      delete (static_cast<map<tuple<int,int>,grams::MCLArHit>*>(p));
   }
   static void deleteArray_maplEtuplelEintcOintgRcOgramscLcLMCLArHitgR(void *p) {
      delete [] (static_cast<map<tuple<int,int>,grams::MCLArHit>*>(p));
   }
   static void destruct_maplEtuplelEintcOintgRcOgramscLcLMCLArHitgR(void *p) {
      typedef map<tuple<int,int>,grams::MCLArHit> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class map<tuple<int,int>,grams::MCLArHit>

namespace ROOT {
   static TClass *maplEtuplelEintcOintcOintgRcOgramscLcLElectronClustergR_Dictionary();
   static void maplEtuplelEintcOintcOintgRcOgramscLcLElectronClustergR_TClassManip(TClass*);
   static void *new_maplEtuplelEintcOintcOintgRcOgramscLcLElectronClustergR(void *p = nullptr);
   static void *newArray_maplEtuplelEintcOintcOintgRcOgramscLcLElectronClustergR(Long_t size, void *p);
   static void delete_maplEtuplelEintcOintcOintgRcOgramscLcLElectronClustergR(void *p);
   static void deleteArray_maplEtuplelEintcOintcOintgRcOgramscLcLElectronClustergR(void *p);
   static void destruct_maplEtuplelEintcOintcOintgRcOgramscLcLElectronClustergR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<tuple<int,int,int>,grams::ElectronCluster>*)
   {
      map<tuple<int,int,int>,grams::ElectronCluster> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<tuple<int,int,int>,grams::ElectronCluster>));
      static ::ROOT::TGenericClassInfo 
         instance("map<tuple<int,int,int>,grams::ElectronCluster>", -2, "map", 100,
                  typeid(map<tuple<int,int,int>,grams::ElectronCluster>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &maplEtuplelEintcOintcOintgRcOgramscLcLElectronClustergR_Dictionary, isa_proxy, 4,
                  sizeof(map<tuple<int,int,int>,grams::ElectronCluster>) );
      instance.SetNew(&new_maplEtuplelEintcOintcOintgRcOgramscLcLElectronClustergR);
      instance.SetNewArray(&newArray_maplEtuplelEintcOintcOintgRcOgramscLcLElectronClustergR);
      instance.SetDelete(&delete_maplEtuplelEintcOintcOintgRcOgramscLcLElectronClustergR);
      instance.SetDeleteArray(&deleteArray_maplEtuplelEintcOintcOintgRcOgramscLcLElectronClustergR);
      instance.SetDestructor(&destruct_maplEtuplelEintcOintcOintgRcOgramscLcLElectronClustergR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<tuple<int,int,int>,grams::ElectronCluster> >()));

      ::ROOT::AddClassAlternate("map<tuple<int,int,int>,grams::ElectronCluster>","std::map<std::tuple<int, int, int>, grams::ElectronCluster, std::less<std::tuple<int, int, int> >, std::allocator<std::pair<std::tuple<int, int, int> const, grams::ElectronCluster> > >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const map<tuple<int,int,int>,grams::ElectronCluster>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEtuplelEintcOintcOintgRcOgramscLcLElectronClustergR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const map<tuple<int,int,int>,grams::ElectronCluster>*>(nullptr))->GetClass();
      maplEtuplelEintcOintcOintgRcOgramscLcLElectronClustergR_TClassManip(theClass);
   return theClass;
   }

   static void maplEtuplelEintcOintcOintgRcOgramscLcLElectronClustergR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEtuplelEintcOintcOintgRcOgramscLcLElectronClustergR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<tuple<int,int,int>,grams::ElectronCluster> : new map<tuple<int,int,int>,grams::ElectronCluster>;
   }
   static void *newArray_maplEtuplelEintcOintcOintgRcOgramscLcLElectronClustergR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<tuple<int,int,int>,grams::ElectronCluster>[nElements] : new map<tuple<int,int,int>,grams::ElectronCluster>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEtuplelEintcOintcOintgRcOgramscLcLElectronClustergR(void *p) {
      delete (static_cast<map<tuple<int,int,int>,grams::ElectronCluster>*>(p));
   }
   static void deleteArray_maplEtuplelEintcOintcOintgRcOgramscLcLElectronClustergR(void *p) {
      delete [] (static_cast<map<tuple<int,int,int>,grams::ElectronCluster>*>(p));
   }
   static void destruct_maplEtuplelEintcOintcOintgRcOgramscLcLElectronClustergR(void *p) {
      typedef map<tuple<int,int,int>,grams::ElectronCluster> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class map<tuple<int,int,int>,grams::ElectronCluster>

namespace ROOT {
   static TClass *maplEintcOgramscLcLMCTrackgR_Dictionary();
   static void maplEintcOgramscLcLMCTrackgR_TClassManip(TClass*);
   static void *new_maplEintcOgramscLcLMCTrackgR(void *p = nullptr);
   static void *newArray_maplEintcOgramscLcLMCTrackgR(Long_t size, void *p);
   static void delete_maplEintcOgramscLcLMCTrackgR(void *p);
   static void deleteArray_maplEintcOgramscLcLMCTrackgR(void *p);
   static void destruct_maplEintcOgramscLcLMCTrackgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<int,grams::MCTrack>*)
   {
      map<int,grams::MCTrack> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<int,grams::MCTrack>));
      static ::ROOT::TGenericClassInfo 
         instance("map<int,grams::MCTrack>", -2, "map", 100,
                  typeid(map<int,grams::MCTrack>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &maplEintcOgramscLcLMCTrackgR_Dictionary, isa_proxy, 4,
                  sizeof(map<int,grams::MCTrack>) );
      instance.SetNew(&new_maplEintcOgramscLcLMCTrackgR);
      instance.SetNewArray(&newArray_maplEintcOgramscLcLMCTrackgR);
      instance.SetDelete(&delete_maplEintcOgramscLcLMCTrackgR);
      instance.SetDeleteArray(&deleteArray_maplEintcOgramscLcLMCTrackgR);
      instance.SetDestructor(&destruct_maplEintcOgramscLcLMCTrackgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<int,grams::MCTrack> >()));

      ::ROOT::AddClassAlternate("map<int,grams::MCTrack>","std::map<int, grams::MCTrack, std::less<int>, std::allocator<std::pair<int const, grams::MCTrack> > >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const map<int,grams::MCTrack>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEintcOgramscLcLMCTrackgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const map<int,grams::MCTrack>*>(nullptr))->GetClass();
      maplEintcOgramscLcLMCTrackgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEintcOgramscLcLMCTrackgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEintcOgramscLcLMCTrackgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<int,grams::MCTrack> : new map<int,grams::MCTrack>;
   }
   static void *newArray_maplEintcOgramscLcLMCTrackgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<int,grams::MCTrack>[nElements] : new map<int,grams::MCTrack>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEintcOgramscLcLMCTrackgR(void *p) {
      delete (static_cast<map<int,grams::MCTrack>*>(p));
   }
   static void deleteArray_maplEintcOgramscLcLMCTrackgR(void *p) {
      delete [] (static_cast<map<int,grams::MCTrack>*>(p));
   }
   static void destruct_maplEintcOgramscLcLMCTrackgR(void *p) {
      typedef map<int,grams::MCTrack> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class map<int,grams::MCTrack>

namespace ROOT {
   static TClass *maplEgramscLcLReadoutIDcOsetlEtuplelEintcOintcOintgRsPgRsPgR_Dictionary();
   static void maplEgramscLcLReadoutIDcOsetlEtuplelEintcOintcOintgRsPgRsPgR_TClassManip(TClass*);
   static void *new_maplEgramscLcLReadoutIDcOsetlEtuplelEintcOintcOintgRsPgRsPgR(void *p = nullptr);
   static void *newArray_maplEgramscLcLReadoutIDcOsetlEtuplelEintcOintcOintgRsPgRsPgR(Long_t size, void *p);
   static void delete_maplEgramscLcLReadoutIDcOsetlEtuplelEintcOintcOintgRsPgRsPgR(void *p);
   static void deleteArray_maplEgramscLcLReadoutIDcOsetlEtuplelEintcOintcOintgRsPgRsPgR(void *p);
   static void destruct_maplEgramscLcLReadoutIDcOsetlEtuplelEintcOintcOintgRsPgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<grams::ReadoutID,set<tuple<int,int,int> > >*)
   {
      map<grams::ReadoutID,set<tuple<int,int,int> > > *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<grams::ReadoutID,set<tuple<int,int,int> > >));
      static ::ROOT::TGenericClassInfo 
         instance("map<grams::ReadoutID,set<tuple<int,int,int> > >", -2, "map", 100,
                  typeid(map<grams::ReadoutID,set<tuple<int,int,int> > >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &maplEgramscLcLReadoutIDcOsetlEtuplelEintcOintcOintgRsPgRsPgR_Dictionary, isa_proxy, 4,
                  sizeof(map<grams::ReadoutID,set<tuple<int,int,int> > >) );
      instance.SetNew(&new_maplEgramscLcLReadoutIDcOsetlEtuplelEintcOintcOintgRsPgRsPgR);
      instance.SetNewArray(&newArray_maplEgramscLcLReadoutIDcOsetlEtuplelEintcOintcOintgRsPgRsPgR);
      instance.SetDelete(&delete_maplEgramscLcLReadoutIDcOsetlEtuplelEintcOintcOintgRsPgRsPgR);
      instance.SetDeleteArray(&deleteArray_maplEgramscLcLReadoutIDcOsetlEtuplelEintcOintcOintgRsPgRsPgR);
      instance.SetDestructor(&destruct_maplEgramscLcLReadoutIDcOsetlEtuplelEintcOintcOintgRsPgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<grams::ReadoutID,set<tuple<int,int,int> > > >()));

      ::ROOT::AddClassAlternate("map<grams::ReadoutID,set<tuple<int,int,int> > >","std::map<grams::ReadoutID, std::set<std::tuple<int, int, int>, std::less<std::tuple<int, int, int> >, std::allocator<std::tuple<int, int, int> > >, std::less<grams::ReadoutID>, std::allocator<std::pair<grams::ReadoutID const, std::set<std::tuple<int, int, int>, std::less<std::tuple<int, int, int> >, std::allocator<std::tuple<int, int, int> > > > > >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const map<grams::ReadoutID,set<tuple<int,int,int> > >*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEgramscLcLReadoutIDcOsetlEtuplelEintcOintcOintgRsPgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const map<grams::ReadoutID,set<tuple<int,int,int> > >*>(nullptr))->GetClass();
      maplEgramscLcLReadoutIDcOsetlEtuplelEintcOintcOintgRsPgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEgramscLcLReadoutIDcOsetlEtuplelEintcOintcOintgRsPgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEgramscLcLReadoutIDcOsetlEtuplelEintcOintcOintgRsPgRsPgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<grams::ReadoutID,set<tuple<int,int,int> > > : new map<grams::ReadoutID,set<tuple<int,int,int> > >;
   }
   static void *newArray_maplEgramscLcLReadoutIDcOsetlEtuplelEintcOintcOintgRsPgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<grams::ReadoutID,set<tuple<int,int,int> > >[nElements] : new map<grams::ReadoutID,set<tuple<int,int,int> > >[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEgramscLcLReadoutIDcOsetlEtuplelEintcOintcOintgRsPgRsPgR(void *p) {
      delete (static_cast<map<grams::ReadoutID,set<tuple<int,int,int> > >*>(p));
   }
   static void deleteArray_maplEgramscLcLReadoutIDcOsetlEtuplelEintcOintcOintgRsPgRsPgR(void *p) {
      delete [] (static_cast<map<grams::ReadoutID,set<tuple<int,int,int> > >*>(p));
   }
   static void destruct_maplEgramscLcLReadoutIDcOsetlEtuplelEintcOintcOintgRsPgRsPgR(void *p) {
      typedef map<grams::ReadoutID,set<tuple<int,int,int> > > current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class map<grams::ReadoutID,set<tuple<int,int,int> > >

namespace ROOT {
   static TClass *maplEgramscLcLReadoutIDcOgramscLcLReadoutWaveformgR_Dictionary();
   static void maplEgramscLcLReadoutIDcOgramscLcLReadoutWaveformgR_TClassManip(TClass*);
   static void *new_maplEgramscLcLReadoutIDcOgramscLcLReadoutWaveformgR(void *p = nullptr);
   static void *newArray_maplEgramscLcLReadoutIDcOgramscLcLReadoutWaveformgR(Long_t size, void *p);
   static void delete_maplEgramscLcLReadoutIDcOgramscLcLReadoutWaveformgR(void *p);
   static void deleteArray_maplEgramscLcLReadoutIDcOgramscLcLReadoutWaveformgR(void *p);
   static void destruct_maplEgramscLcLReadoutIDcOgramscLcLReadoutWaveformgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<grams::ReadoutID,grams::ReadoutWaveform>*)
   {
      map<grams::ReadoutID,grams::ReadoutWaveform> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<grams::ReadoutID,grams::ReadoutWaveform>));
      static ::ROOT::TGenericClassInfo 
         instance("map<grams::ReadoutID,grams::ReadoutWaveform>", -2, "map", 100,
                  typeid(map<grams::ReadoutID,grams::ReadoutWaveform>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &maplEgramscLcLReadoutIDcOgramscLcLReadoutWaveformgR_Dictionary, isa_proxy, 4,
                  sizeof(map<grams::ReadoutID,grams::ReadoutWaveform>) );
      instance.SetNew(&new_maplEgramscLcLReadoutIDcOgramscLcLReadoutWaveformgR);
      instance.SetNewArray(&newArray_maplEgramscLcLReadoutIDcOgramscLcLReadoutWaveformgR);
      instance.SetDelete(&delete_maplEgramscLcLReadoutIDcOgramscLcLReadoutWaveformgR);
      instance.SetDeleteArray(&deleteArray_maplEgramscLcLReadoutIDcOgramscLcLReadoutWaveformgR);
      instance.SetDestructor(&destruct_maplEgramscLcLReadoutIDcOgramscLcLReadoutWaveformgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<grams::ReadoutID,grams::ReadoutWaveform> >()));

      ::ROOT::AddClassAlternate("map<grams::ReadoutID,grams::ReadoutWaveform>","std::map<grams::ReadoutID, grams::ReadoutWaveform, std::less<grams::ReadoutID>, std::allocator<std::pair<grams::ReadoutID const, grams::ReadoutWaveform> > >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const map<grams::ReadoutID,grams::ReadoutWaveform>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEgramscLcLReadoutIDcOgramscLcLReadoutWaveformgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const map<grams::ReadoutID,grams::ReadoutWaveform>*>(nullptr))->GetClass();
      maplEgramscLcLReadoutIDcOgramscLcLReadoutWaveformgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEgramscLcLReadoutIDcOgramscLcLReadoutWaveformgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEgramscLcLReadoutIDcOgramscLcLReadoutWaveformgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<grams::ReadoutID,grams::ReadoutWaveform> : new map<grams::ReadoutID,grams::ReadoutWaveform>;
   }
   static void *newArray_maplEgramscLcLReadoutIDcOgramscLcLReadoutWaveformgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<grams::ReadoutID,grams::ReadoutWaveform>[nElements] : new map<grams::ReadoutID,grams::ReadoutWaveform>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEgramscLcLReadoutIDcOgramscLcLReadoutWaveformgR(void *p) {
      delete (static_cast<map<grams::ReadoutID,grams::ReadoutWaveform>*>(p));
   }
   static void deleteArray_maplEgramscLcLReadoutIDcOgramscLcLReadoutWaveformgR(void *p) {
      delete [] (static_cast<map<grams::ReadoutID,grams::ReadoutWaveform>*>(p));
   }
   static void destruct_maplEgramscLcLReadoutIDcOgramscLcLReadoutWaveformgR(void *p) {
      typedef map<grams::ReadoutID,grams::ReadoutWaveform> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class map<grams::ReadoutID,grams::ReadoutWaveform>

namespace {
  void TriggerDictionaryInitialization_Dictionary_Impl() {
    static const char* headers[] = {
"/nevis/milne/files/apellot/GRAMS/GramsSim/GramsDataObj/include/ElectronClusters.h",
"/nevis/milne/files/apellot/GRAMS/GramsSim/GramsDataObj/include/EventID.h",
"/nevis/milne/files/apellot/GRAMS/GramsSim/GramsDataObj/include/MCLArHits.h",
"/nevis/milne/files/apellot/GRAMS/GramsSim/GramsDataObj/include/MCScintHits.h",
"/nevis/milne/files/apellot/GRAMS/GramsSim/GramsDataObj/include/MCTrackList.h",
"/nevis/milne/files/apellot/GRAMS/GramsSim/GramsDataObj/include/ReadoutID.h",
"/nevis/milne/files/apellot/GRAMS/GramsSim/GramsDataObj/include/ReadoutMap.h",
"/nevis/milne/files/apellot/GRAMS/GramsSim/GramsDataObj/include/ReadoutWaveforms.h",
nullptr
    };
    static const char* includePaths[] = {
"/nevis/amsterdam/share/seligman/conda/grams/include/Geant4",
"/nevis/amsterdam/share/seligman/conda/grams/include",
"/nevis/amsterdam/share/seligman/conda/grams/include",
"/nevis/amsterdam/share/seligman/conda/grams/include",
"/nevis/amsterdam/share/seligman/conda/grams/include/healpix_cxx",
"/nevis/amsterdam/share/seligman/conda/grams/include/",
"/nevis/milne/files/apellot/GRAMS/GramsSim-work/GramsDataObj/",
nullptr
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "Dictionary dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
namespace std{template <typename ...> class __attribute__((annotate("$clingAutoload$bits/stl_pair.h")))  __attribute__((annotate("$clingAutoload$string")))  tuple;
}
namespace grams{struct __attribute__((annotate("$clingAutoload$/nevis/milne/files/apellot/GRAMS/GramsSim/GramsDataObj/include/MCTrackList.h")))  MCTrajectoryPoint;}
namespace std{template <typename _Tp> class __attribute__((annotate("$clingAutoload$bits/allocator.h")))  __attribute__((annotate("$clingAutoload$string")))  allocator;
}
namespace grams{struct __attribute__((annotate("$clingAutoload$/nevis/milne/files/apellot/GRAMS/GramsSim/GramsDataObj/include/ElectronClusters.h")))  ElectronCluster;}
namespace std{template <typename _Tp = void> struct __attribute__((annotate("$clingAutoload$bits/stl_function.h")))  __attribute__((annotate("$clingAutoload$string")))  less;
}
namespace std{template <typename _T1, typename _T2> struct __attribute__((annotate("$clingAutoload$bits/stl_pair.h")))  __attribute__((annotate("$clingAutoload$string")))  pair;
}
namespace grams{struct __attribute__((annotate("$clingAutoload$/nevis/milne/files/apellot/GRAMS/GramsSim/GramsDataObj/include/MCLArHits.h")))  MCLArHit;}
namespace grams{struct __attribute__((annotate("$clingAutoload$/nevis/milne/files/apellot/GRAMS/GramsSim/GramsDataObj/include/MCScintHits.h")))  MCScintHit;}
namespace grams{class __attribute__((annotate("$clingAutoload$/nevis/milne/files/apellot/GRAMS/GramsSim/GramsDataObj/include/MCTrackList.h")))  MCTrack;}
namespace grams{class __attribute__((annotate("$clingAutoload$/nevis/milne/files/apellot/GRAMS/GramsSim/GramsDataObj/include/ReadoutID.h")))  ReadoutID;}
namespace grams{struct __attribute__((annotate("$clingAutoload$/nevis/milne/files/apellot/GRAMS/GramsSim/GramsDataObj/include/ReadoutWaveforms.h")))  ReadoutWaveform;}
namespace grams{class __attribute__((annotate("$clingAutoload$/nevis/milne/files/apellot/GRAMS/GramsSim/GramsDataObj/include/EventID.h")))  EventID;}
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "Dictionary dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "/nevis/milne/files/apellot/GRAMS/GramsSim/GramsDataObj/include/ElectronClusters.h"
#include "/nevis/milne/files/apellot/GRAMS/GramsSim/GramsDataObj/include/EventID.h"
#include "/nevis/milne/files/apellot/GRAMS/GramsSim/GramsDataObj/include/MCLArHits.h"
#include "/nevis/milne/files/apellot/GRAMS/GramsSim/GramsDataObj/include/MCScintHits.h"
#include "/nevis/milne/files/apellot/GRAMS/GramsSim/GramsDataObj/include/MCTrackList.h"
#include "/nevis/milne/files/apellot/GRAMS/GramsSim/GramsDataObj/include/ReadoutID.h"
#include "/nevis/milne/files/apellot/GRAMS/GramsSim/GramsDataObj/include/ReadoutMap.h"
#include "/nevis/milne/files/apellot/GRAMS/GramsSim/GramsDataObj/include/ReadoutWaveforms.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"grams::ClusterKeys", payloadCode, "@",
"grams::ElectronCluster", payloadCode, "@",
"grams::ElectronClusters", payloadCode, "@",
"grams::EventID", payloadCode, "@",
"grams::MCLArHit", payloadCode, "@",
"grams::MCLArHits", payloadCode, "@",
"grams::MCScintHit", payloadCode, "@",
"grams::MCScintHits", payloadCode, "@",
"grams::MCTrack", payloadCode, "@",
"grams::MCTrackList", payloadCode, "@",
"grams::MCTrajectory", payloadCode, "@",
"grams::MCTrajectoryPoint", payloadCode, "@",
"grams::ReadoutID", payloadCode, "@",
"grams::ReadoutMap", payloadCode, "@",
"grams::ReadoutWaveform", payloadCode, "@",
"grams::ReadoutWaveforms", payloadCode, "@",
"tuple<int,int,int>", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("Dictionary",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_Dictionary_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_Dictionary_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_Dictionary() {
  TriggerDictionaryInitialization_Dictionary_Impl();
}
