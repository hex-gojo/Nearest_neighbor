; ModuleID = 'D:/gojo/workspace/V_HLS/Vivado_HLS_2017-4/Nearest_neighbor/solution1/.autopilot/db/a.o.2.bc'
target datalayout = "e-p:64:64:64-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v64:64:64-v128:128:128-a0:0:64-s0:64:64-f80:128:128-n8:16:32:64-S128"
target triple = "x86_64-w64-mingw32"

@nearest_neighbor_axim.str = internal unnamed_addr constant [22 x i8] c"nearest_neighbor_axim\00" ; [#uses=1 type=[22 x i8]*]

; [#uses=0]
define i32 @nearest_neighbor_axim([4096 x i32]* %cam_fb, [16384 x i32]* %nn_fb) nounwind uwtable {
  call void (...)* @_ssdm_op_SpecBitsMap([4096 x i32]* %cam_fb) nounwind, !map !22
  call void (...)* @_ssdm_op_SpecBitsMap([16384 x i32]* %nn_fb) nounwind, !map !28
  call void (...)* @_ssdm_op_SpecBitsMap(i32 0) nounwind, !map !34
  call void (...)* @_ssdm_op_SpecTopModule([22 x i8]* @nearest_neighbor_axim.str) nounwind
  call void @llvm.dbg.value(metadata !{[4096 x i32]* %cam_fb}, i64 0, metadata !40), !dbg !44 ; [debug line = 12:49] [debug variable = cam_fb]
  call void @llvm.dbg.value(metadata !{[16384 x i32]* %nn_fb}, i64 0, metadata !45), !dbg !49 ; [debug line = 12:88] [debug variable = nn_fb]
  br label %1, !dbg !50                           ; [debug line = 14:6]

; <label>:1                                       ; preds = %4, %0
  %y = phi i8 [ 0, %0 ], [ %y.1, %4 ]             ; [#uses=4 type=i8]
  %y.cast6 = zext i8 %y to i14, !dbg !50          ; [#uses=1 type=i14] [debug line = 14:6]
  %exitcond1 = icmp eq i8 %y, -128, !dbg !50      ; [#uses=1 type=i1] [debug line = 14:6]
  %2 = call i32 (...)* @_ssdm_op_SpecLoopTripCount(i64 128, i64 128, i64 128) nounwind ; [#uses=0 type=i32]
  br i1 %exitcond1, label %5, label %.preheader.preheader, !dbg !50 ; [debug line = 14:6]

.preheader.preheader:                             ; preds = %1
  %y.tr.cast = trunc i8 %y to i7, !dbg !53        ; [#uses=1 type=i7] [debug line = 17:4]
  %_lshr.f = lshr i7 %y.tr.cast, 1, !dbg !53      ; [#uses=1 type=i7] [debug line = 17:4]
  %_lshr.f.cast = trunc i7 %_lshr.f to i6, !dbg !53 ; [#uses=1 type=i6] [debug line = 17:4]
  %tmp.2 = shl i14 %y.cast6, 7, !dbg !57          ; [#uses=1 type=i14] [debug line = 20:5]
  br label %.preheader, !dbg !59                  ; [debug line = 15:7]

.preheader:                                       ; preds = %._crit_edge, %.preheader.preheader
  %x = phi i8 [ %x.1, %._crit_edge ], [ 0, %.preheader.preheader ] ; [#uses=4 type=i8]
  %x.cast3 = zext i8 %x to i14, !dbg !59          ; [#uses=1 type=i14] [debug line = 15:7]
  %exitcond = icmp eq i8 %x, -128, !dbg !59       ; [#uses=1 type=i1] [debug line = 15:7]
  %3 = call i32 (...)* @_ssdm_op_SpecLoopTripCount(i64 128, i64 128, i64 128) nounwind ; [#uses=0 type=i32]
  br i1 %exitcond, label %4, label %._crit_edge, !dbg !59 ; [debug line = 15:7]

._crit_edge:                                      ; preds = %.preheader
  %x.tr.cast = trunc i8 %x to i7, !dbg !60        ; [#uses=1 type=i7] [debug line = 16:4]
  %_lshr.f1 = lshr i7 %x.tr.cast, 1, !dbg !60     ; [#uses=1 type=i7] [debug line = 16:4]
  %_lshr.f1.cast = trunc i7 %_lshr.f1 to i6, !dbg !60 ; [#uses=1 type=i6] [debug line = 16:4]
  %tmp.5 = call i12 @_ssdm_op_BitConcatenate.i12.i6.i6(i6 %_lshr.f.cast, i6 %_lshr.f1.cast), !dbg !57 ; [#uses=1 type=i12] [debug line = 20:5]
  %tmp.6 = zext i12 %tmp.5 to i64, !dbg !57       ; [#uses=1 type=i64] [debug line = 20:5]
  %cam_fb.addr = getelementptr [4096 x i32]* %cam_fb, i64 0, i64 %tmp.6, !dbg !57 ; [#uses=1 type=i32*] [debug line = 20:5]
  %cam_fb.load = load volatile i32* %cam_fb.addr, align 4, !dbg !57 ; [#uses=1 type=i32] [debug line = 20:5]
  %tmp.7 = add i14 %tmp.2, %x.cast3, !dbg !57     ; [#uses=1 type=i14] [debug line = 20:5]
  %tmp.8 = zext i14 %tmp.7 to i64, !dbg !57       ; [#uses=1 type=i64] [debug line = 20:5]
  %nn_fb.addr = getelementptr [16384 x i32]* %nn_fb, i64 0, i64 %tmp.8, !dbg !57 ; [#uses=1 type=i32*] [debug line = 20:5]
  store volatile i32 %cam_fb.load, i32* %nn_fb.addr, align 4, !dbg !57 ; [debug line = 20:5]
  %x.1 = add i8 %x, 1, !dbg !61                   ; [#uses=1 type=i8] [debug line = 15:23]
  call void @llvm.dbg.value(metadata !{i8 %x.1}, i64 0, metadata !62), !dbg !61 ; [debug line = 15:23] [debug variable = x]
  br label %.preheader, !dbg !61                  ; [debug line = 15:23]

; <label>:4                                       ; preds = %.preheader
  %y.1 = add i8 %y, 1, !dbg !63                   ; [#uses=1 type=i8] [debug line = 14:22]
  call void @llvm.dbg.value(metadata !{i8 %y.1}, i64 0, metadata !64), !dbg !63 ; [debug line = 14:22] [debug variable = y]
  br label %1, !dbg !63                           ; [debug line = 14:22]

; <label>:5                                       ; preds = %1
  ret i32 0, !dbg !65                             ; [debug line = 24:2]
}

; [#uses=4]
declare void @llvm.dbg.value(metadata, i64, metadata) nounwind readnone

; [#uses=1]
declare void @_ssdm_op_SpecTopModule(...)

; [#uses=2]
declare i32 @_ssdm_op_SpecLoopTripCount(...)

; [#uses=3]
declare void @_ssdm_op_SpecBitsMap(...)

; [#uses=0]
declare i6 @_ssdm_op_PartSelect.i6.i6.i32.i32(i6, i32, i32) nounwind readnone

; [#uses=0]
declare i6 @_ssdm_op_PartSelect.i6.i12.i32.i32(i12, i32, i32) nounwind readnone

; [#uses=1]
declare i12 @_ssdm_op_BitConcatenate.i12.i6.i6(i6, i6) nounwind readnone

!llvm.dbg.cu = !{!0}
!opencl.kernels = !{!15}
!hls.encrypted.func = !{}
!llvm.map.gv = !{}

!0 = metadata !{i32 786449, i32 0, i32 1, metadata !"D:/gojo/workspace/V_HLS/Vivado_HLS_2017-4/Nearest_neighbor/solution1/.autopilot/db/nearest_neighbor.pragma.2.c", metadata !"D:\5Cgojo\5Cworkspace\5CV_HLS\5CVivado_HLS_2017-4", metadata !"clang version 3.1 ", i1 true, i1 false, metadata !"", i32 0, metadata !1, metadata !1, metadata !3, metadata !1} ; [ DW_TAG_compile_unit ]
!1 = metadata !{metadata !2}
!2 = metadata !{i32 0}
!3 = metadata !{metadata !4}
!4 = metadata !{metadata !5}
!5 = metadata !{i32 786478, i32 0, metadata !6, metadata !"nearest_neighbor_axim", metadata !"nearest_neighbor_axim", metadata !"", metadata !6, i32 12, metadata !7, i1 false, i1 true, i32 0, i32 0, null, i32 256, i1 false, null, null, null, metadata !13, i32 12} ; [ DW_TAG_subprogram ]
!6 = metadata !{i32 786473, metadata !"Nearest_neighbor/nearest_neighbor.c", metadata !"D:\5Cgojo\5Cworkspace\5CV_HLS\5CVivado_HLS_2017-4", null} ; [ DW_TAG_file_type ]
!7 = metadata !{i32 786453, i32 0, metadata !"", i32 0, i32 0, i64 0, i64 0, i64 0, i32 0, null, metadata !8, i32 0, i32 0} ; [ DW_TAG_subroutine_type ]
!8 = metadata !{metadata !9, metadata !10, metadata !10}
!9 = metadata !{i32 786468, null, metadata !"int", null, i32 0, i64 32, i64 32, i64 0, i32 0, i32 5} ; [ DW_TAG_base_type ]
!10 = metadata !{i32 786447, null, metadata !"", null, i32 0, i64 64, i64 64, i64 0, i32 0, metadata !11} ; [ DW_TAG_pointer_type ]
!11 = metadata !{i32 786485, null, metadata !"", null, i32 0, i64 0, i64 0, i64 0, i32 0, metadata !12} ; [ DW_TAG_volatile_type ]
!12 = metadata !{i32 786468, null, metadata !"unsigned int", null, i32 0, i64 32, i64 32, i64 0, i32 0, i32 7} ; [ DW_TAG_base_type ]
!13 = metadata !{metadata !14}
!14 = metadata !{i32 786468}                      ; [ DW_TAG_base_type ]
!15 = metadata !{null, metadata !16, metadata !17, metadata !18, metadata !19, metadata !20, metadata !21}
!16 = metadata !{metadata !"kernel_arg_addr_space", i32 1, i32 1}
!17 = metadata !{metadata !"kernel_arg_access_qual", metadata !"none", metadata !"none"}
!18 = metadata !{metadata !"kernel_arg_type", metadata !"uint*", metadata !"uint*"}
!19 = metadata !{metadata !"kernel_arg_type_qual", metadata !"volatile", metadata !"volatile"}
!20 = metadata !{metadata !"kernel_arg_name", metadata !"cam_fb", metadata !"nn_fb"}
!21 = metadata !{metadata !"reqd_work_group_size", i32 1, i32 1, i32 1}
!22 = metadata !{metadata !23}
!23 = metadata !{i32 0, i32 31, metadata !24}
!24 = metadata !{metadata !25}
!25 = metadata !{metadata !"cam_fb", metadata !26, metadata !"unsigned int", i32 0, i32 31}
!26 = metadata !{metadata !27}
!27 = metadata !{i32 0, i32 4095, i32 1}
!28 = metadata !{metadata !29}
!29 = metadata !{i32 0, i32 31, metadata !30}
!30 = metadata !{metadata !31}
!31 = metadata !{metadata !"nn_fb", metadata !32, metadata !"unsigned int", i32 0, i32 31}
!32 = metadata !{metadata !33}
!33 = metadata !{i32 0, i32 16383, i32 1}
!34 = metadata !{metadata !35}
!35 = metadata !{i32 0, i32 31, metadata !36}
!36 = metadata !{metadata !37}
!37 = metadata !{metadata !"return", metadata !38, metadata !"int", i32 0, i32 31}
!38 = metadata !{metadata !39}
!39 = metadata !{i32 0, i32 1, i32 0}
!40 = metadata !{i32 786689, metadata !5, metadata !"cam_fb", null, i32 12, metadata !41, i32 0, i32 0} ; [ DW_TAG_arg_variable ]
!41 = metadata !{i32 786433, null, metadata !"", null, i32 0, i64 0, i64 0, i32 0, i32 0, metadata !11, metadata !42, i32 0, i32 0} ; [ DW_TAG_array_type ]
!42 = metadata !{metadata !43}
!43 = metadata !{i32 786465, i64 0, i64 4095}     ; [ DW_TAG_subrange_type ]
!44 = metadata !{i32 12, i32 49, metadata !5, null}
!45 = metadata !{i32 786689, metadata !5, metadata !"nn_fb", null, i32 12, metadata !46, i32 0, i32 0} ; [ DW_TAG_arg_variable ]
!46 = metadata !{i32 786433, null, metadata !"", null, i32 0, i64 0, i64 0, i32 0, i32 0, metadata !11, metadata !47, i32 0, i32 0} ; [ DW_TAG_array_type ]
!47 = metadata !{metadata !48}
!48 = metadata !{i32 786465, i64 0, i64 16383}    ; [ DW_TAG_subrange_type ]
!49 = metadata !{i32 12, i32 88, metadata !5, null}
!50 = metadata !{i32 14, i32 6, metadata !51, null}
!51 = metadata !{i32 786443, metadata !52, i32 14, i32 2, metadata !6, i32 1} ; [ DW_TAG_lexical_block ]
!52 = metadata !{i32 786443, metadata !5, i32 12, i32 105, metadata !6, i32 0} ; [ DW_TAG_lexical_block ]
!53 = metadata !{i32 17, i32 4, metadata !54, null}
!54 = metadata !{i32 786443, metadata !55, i32 15, i32 27, metadata !6, i32 4} ; [ DW_TAG_lexical_block ]
!55 = metadata !{i32 786443, metadata !56, i32 15, i32 3, metadata !6, i32 3} ; [ DW_TAG_lexical_block ]
!56 = metadata !{i32 786443, metadata !51, i32 14, i32 26, metadata !6, i32 2} ; [ DW_TAG_lexical_block ]
!57 = metadata !{i32 20, i32 5, metadata !58, null}
!58 = metadata !{i32 786443, metadata !54, i32 19, i32 26, metadata !6, i32 5} ; [ DW_TAG_lexical_block ]
!59 = metadata !{i32 15, i32 7, metadata !55, null}
!60 = metadata !{i32 16, i32 4, metadata !54, null}
!61 = metadata !{i32 15, i32 23, metadata !55, null}
!62 = metadata !{i32 786688, metadata !52, metadata !"x", metadata !6, i32 13, metadata !9, i32 0, i32 0} ; [ DW_TAG_auto_variable ]
!63 = metadata !{i32 14, i32 22, metadata !51, null}
!64 = metadata !{i32 786688, metadata !52, metadata !"y", metadata !6, i32 13, metadata !9, i32 0, i32 0} ; [ DW_TAG_auto_variable ]
!65 = metadata !{i32 24, i32 2, metadata !52, null}
