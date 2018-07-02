; ModuleID = 'D:/gojo/workspace/V_HLS/Vivado_HLS_2017-4/Nearest_neighbor/solution1/.autopilot/db/a.o.3.bc'
target datalayout = "e-p:64:64:64-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v64:64:64-v128:128:128-a0:0:64-s0:64:64-f80:128:128-n8:16:32:64-S128"
target triple = "x86_64-w64-mingw32"

@nearest_neighbor_axi = internal unnamed_addr constant [22 x i8] c"nearest_neighbor_axim\00" ; [#uses=1 type=[22 x i8]*]

; [#uses=0]
define i32 @nearest_neighbor_axim([4096 x i32]* %cam_fb, [16384 x i32]* %nn_fb) nounwind uwtable {
  call void (...)* @_ssdm_op_SpecBitsMap([4096 x i32]* %cam_fb) nounwind, !map !7
  call void (...)* @_ssdm_op_SpecBitsMap([16384 x i32]* %nn_fb) nounwind, !map !13
  call void (...)* @_ssdm_op_SpecBitsMap(i32 0) nounwind, !map !19
  call void (...)* @_ssdm_op_SpecTopModule([22 x i8]* @nearest_neighbor_axi) nounwind
  call void @llvm.dbg.value(metadata !{[4096 x i32]* %cam_fb}, i64 0, metadata !25), !dbg !39 ; [debug line = 12:49] [debug variable = cam_fb]
  call void @llvm.dbg.value(metadata !{[16384 x i32]* %nn_fb}, i64 0, metadata !40), !dbg !44 ; [debug line = 12:88] [debug variable = nn_fb]
  br label %.loopexit, !dbg !45                   ; [debug line = 14:6]

.loopexit.loopexit:                               ; preds = %.preheader
  br label %.loopexit

.loopexit:                                        ; preds = %.loopexit.loopexit, %0
  %y = phi i8 [ 0, %0 ], [ %y_1, %.loopexit.loopexit ] ; [#uses=4 type=i8]
  %exitcond1 = icmp eq i8 %y, -128, !dbg !45      ; [#uses=1 type=i1] [debug line = 14:6]
  %empty = call i32 (...)* @_ssdm_op_SpecLoopTripCount(i64 128, i64 128, i64 128) nounwind ; [#uses=0 type=i32]
  %y_1 = add i8 %y, 1, !dbg !48                   ; [#uses=1 type=i8] [debug line = 14:22]
  call void @llvm.dbg.value(metadata !{i8 %y_1}, i64 0, metadata !49), !dbg !48 ; [debug line = 14:22] [debug variable = y]
  br i1 %exitcond1, label %1, label %.preheader.preheader, !dbg !45 ; [debug line = 14:6]

.preheader.preheader:                             ; preds = %.loopexit
  %p_lshr_f_cast = call i6 @_ssdm_op_PartSelect.i6.i8.i32.i32(i8 %y, i32 1, i32 6), !dbg !50 ; [#uses=1 type=i6] [debug line = 17:4]
  %tmp = trunc i8 %y to i7                        ; [#uses=1 type=i7]
  %tmp_2 = call i14 @_ssdm_op_BitConcatenate.i14.i7.i7(i7 %tmp, i7 0), !dbg !54 ; [#uses=1 type=i14] [debug line = 20:5]
  br label %.preheader, !dbg !56                  ; [debug line = 15:7]

.preheader:                                       ; preds = %._crit_edge, %.preheader.preheader
  %x = phi i8 [ %x_1, %._crit_edge ], [ 0, %.preheader.preheader ] ; [#uses=4 type=i8]
  %x_cast3 = zext i8 %x to i14, !dbg !56          ; [#uses=1 type=i14] [debug line = 15:7]
  %exitcond = icmp eq i8 %x, -128, !dbg !56       ; [#uses=1 type=i1] [debug line = 15:7]
  %empty_4 = call i32 (...)* @_ssdm_op_SpecLoopTripCount(i64 128, i64 128, i64 128) nounwind ; [#uses=0 type=i32]
  %x_1 = add i8 %x, 1, !dbg !57                   ; [#uses=1 type=i8] [debug line = 15:23]
  br i1 %exitcond, label %.loopexit.loopexit, label %._crit_edge, !dbg !56 ; [debug line = 15:7]

._crit_edge:                                      ; preds = %.preheader
  %p_lshr_f1_cast = call i6 @_ssdm_op_PartSelect.i6.i8.i32.i32(i8 %x, i32 1, i32 6), !dbg !58 ; [#uses=1 type=i6] [debug line = 16:4]
  %tmp_5 = call i12 @_ssdm_op_BitConcatenate.i12.i6.i6(i6 %p_lshr_f_cast, i6 %p_lshr_f1_cast), !dbg !54 ; [#uses=1 type=i12] [debug line = 20:5]
  %tmp_6 = zext i12 %tmp_5 to i64, !dbg !54       ; [#uses=1 type=i64] [debug line = 20:5]
  %cam_fb_addr = getelementptr [4096 x i32]* %cam_fb, i64 0, i64 %tmp_6, !dbg !54 ; [#uses=1 type=i32*] [debug line = 20:5]
  %cam_fb_load = load volatile i32* %cam_fb_addr, align 4, !dbg !54 ; [#uses=1 type=i32] [debug line = 20:5]
  %tmp_7 = add i14 %tmp_2, %x_cast3, !dbg !54     ; [#uses=1 type=i14] [debug line = 20:5]
  %tmp_8 = zext i14 %tmp_7 to i64, !dbg !54       ; [#uses=1 type=i64] [debug line = 20:5]
  %nn_fb_addr = getelementptr [16384 x i32]* %nn_fb, i64 0, i64 %tmp_8, !dbg !54 ; [#uses=1 type=i32*] [debug line = 20:5]
  store volatile i32 %cam_fb_load, i32* %nn_fb_addr, align 4, !dbg !54 ; [debug line = 20:5]
  call void @llvm.dbg.value(metadata !{i8 %x_1}, i64 0, metadata !59), !dbg !57 ; [debug line = 15:23] [debug variable = x]
  br label %.preheader, !dbg !57                  ; [debug line = 15:23]

; <label>:1                                       ; preds = %.loopexit
  ret i32 0, !dbg !60                             ; [debug line = 24:2]
}

; [#uses=1]
declare i8 @llvm.part.select.i8(i8, i32, i32) nounwind readnone

; [#uses=4]
declare void @llvm.dbg.value(metadata, i64, metadata) nounwind readnone

; [#uses=1]
define weak void @_ssdm_op_SpecTopModule(...) {
entry:
  ret void
}

; [#uses=2]
define weak i32 @_ssdm_op_SpecLoopTripCount(...) {
entry:
  ret i32 0
}

; [#uses=3]
define weak void @_ssdm_op_SpecBitsMap(...) {
entry:
  ret void
}

; [#uses=0]
declare i7 @_ssdm_op_PartSelect.i7.i8.i32.i32(i8, i32, i32) nounwind readnone

; [#uses=2]
define weak i6 @_ssdm_op_PartSelect.i6.i8.i32.i32(i8, i32, i32) nounwind readnone {
entry:
  %empty = call i8 @llvm.part.select.i8(i8 %0, i32 %1, i32 %2) ; [#uses=1 type=i8]
  %empty_5 = trunc i8 %empty to i6                ; [#uses=1 type=i6]
  ret i6 %empty_5
}

; [#uses=1]
define weak i14 @_ssdm_op_BitConcatenate.i14.i7.i7(i7, i7) nounwind readnone {
entry:
  %empty = zext i7 %0 to i14                      ; [#uses=1 type=i14]
  %empty_6 = zext i7 %1 to i14                    ; [#uses=1 type=i14]
  %empty_7 = shl i14 %empty, 7                    ; [#uses=1 type=i14]
  %empty_8 = or i14 %empty_7, %empty_6            ; [#uses=1 type=i14]
  ret i14 %empty_8
}

; [#uses=1]
define weak i12 @_ssdm_op_BitConcatenate.i12.i6.i6(i6, i6) nounwind readnone {
entry:
  %empty = zext i6 %0 to i12                      ; [#uses=1 type=i12]
  %empty_9 = zext i6 %1 to i12                    ; [#uses=1 type=i12]
  %empty_10 = shl i12 %empty, 6                   ; [#uses=1 type=i12]
  %empty_11 = or i12 %empty_10, %empty_9          ; [#uses=1 type=i12]
  ret i12 %empty_11
}

!opencl.kernels = !{!0}
!hls.encrypted.func = !{}
!llvm.map.gv = !{}

!0 = metadata !{null, metadata !1, metadata !2, metadata !3, metadata !4, metadata !5, metadata !6}
!1 = metadata !{metadata !"kernel_arg_addr_space", i32 1, i32 1}
!2 = metadata !{metadata !"kernel_arg_access_qual", metadata !"none", metadata !"none"}
!3 = metadata !{metadata !"kernel_arg_type", metadata !"uint*", metadata !"uint*"}
!4 = metadata !{metadata !"kernel_arg_type_qual", metadata !"volatile", metadata !"volatile"}
!5 = metadata !{metadata !"kernel_arg_name", metadata !"cam_fb", metadata !"nn_fb"}
!6 = metadata !{metadata !"reqd_work_group_size", i32 1, i32 1, i32 1}
!7 = metadata !{metadata !8}
!8 = metadata !{i32 0, i32 31, metadata !9}
!9 = metadata !{metadata !10}
!10 = metadata !{metadata !"cam_fb", metadata !11, metadata !"unsigned int", i32 0, i32 31}
!11 = metadata !{metadata !12}
!12 = metadata !{i32 0, i32 4095, i32 1}
!13 = metadata !{metadata !14}
!14 = metadata !{i32 0, i32 31, metadata !15}
!15 = metadata !{metadata !16}
!16 = metadata !{metadata !"nn_fb", metadata !17, metadata !"unsigned int", i32 0, i32 31}
!17 = metadata !{metadata !18}
!18 = metadata !{i32 0, i32 16383, i32 1}
!19 = metadata !{metadata !20}
!20 = metadata !{i32 0, i32 31, metadata !21}
!21 = metadata !{metadata !22}
!22 = metadata !{metadata !"return", metadata !23, metadata !"int", i32 0, i32 31}
!23 = metadata !{metadata !24}
!24 = metadata !{i32 0, i32 1, i32 0}
!25 = metadata !{i32 786689, metadata !26, metadata !"cam_fb", null, i32 12, metadata !36, i32 0, i32 0} ; [ DW_TAG_arg_variable ]
!26 = metadata !{i32 786478, i32 0, metadata !27, metadata !"nearest_neighbor_axim", metadata !"nearest_neighbor_axim", metadata !"", metadata !27, i32 12, metadata !28, i1 false, i1 true, i32 0, i32 0, null, i32 256, i1 false, null, null, null, metadata !34, i32 12} ; [ DW_TAG_subprogram ]
!27 = metadata !{i32 786473, metadata !"Nearest_neighbor/nearest_neighbor.c", metadata !"D:\5Cgojo\5Cworkspace\5CV_HLS\5CVivado_HLS_2017-4", null} ; [ DW_TAG_file_type ]
!28 = metadata !{i32 786453, i32 0, metadata !"", i32 0, i32 0, i64 0, i64 0, i64 0, i32 0, null, metadata !29, i32 0, i32 0} ; [ DW_TAG_subroutine_type ]
!29 = metadata !{metadata !30, metadata !31, metadata !31}
!30 = metadata !{i32 786468, null, metadata !"int", null, i32 0, i64 32, i64 32, i64 0, i32 0, i32 5} ; [ DW_TAG_base_type ]
!31 = metadata !{i32 786447, null, metadata !"", null, i32 0, i64 64, i64 64, i64 0, i32 0, metadata !32} ; [ DW_TAG_pointer_type ]
!32 = metadata !{i32 786485, null, metadata !"", null, i32 0, i64 0, i64 0, i64 0, i32 0, metadata !33} ; [ DW_TAG_volatile_type ]
!33 = metadata !{i32 786468, null, metadata !"unsigned int", null, i32 0, i64 32, i64 32, i64 0, i32 0, i32 7} ; [ DW_TAG_base_type ]
!34 = metadata !{metadata !35}
!35 = metadata !{i32 786468}                      ; [ DW_TAG_base_type ]
!36 = metadata !{i32 786433, null, metadata !"", null, i32 0, i64 0, i64 0, i32 0, i32 0, metadata !32, metadata !37, i32 0, i32 0} ; [ DW_TAG_array_type ]
!37 = metadata !{metadata !38}
!38 = metadata !{i32 786465, i64 0, i64 4095}     ; [ DW_TAG_subrange_type ]
!39 = metadata !{i32 12, i32 49, metadata !26, null}
!40 = metadata !{i32 786689, metadata !26, metadata !"nn_fb", null, i32 12, metadata !41, i32 0, i32 0} ; [ DW_TAG_arg_variable ]
!41 = metadata !{i32 786433, null, metadata !"", null, i32 0, i64 0, i64 0, i32 0, i32 0, metadata !32, metadata !42, i32 0, i32 0} ; [ DW_TAG_array_type ]
!42 = metadata !{metadata !43}
!43 = metadata !{i32 786465, i64 0, i64 16383}    ; [ DW_TAG_subrange_type ]
!44 = metadata !{i32 12, i32 88, metadata !26, null}
!45 = metadata !{i32 14, i32 6, metadata !46, null}
!46 = metadata !{i32 786443, metadata !47, i32 14, i32 2, metadata !27, i32 1} ; [ DW_TAG_lexical_block ]
!47 = metadata !{i32 786443, metadata !26, i32 12, i32 105, metadata !27, i32 0} ; [ DW_TAG_lexical_block ]
!48 = metadata !{i32 14, i32 22, metadata !46, null}
!49 = metadata !{i32 786688, metadata !47, metadata !"y", metadata !27, i32 13, metadata !30, i32 0, i32 0} ; [ DW_TAG_auto_variable ]
!50 = metadata !{i32 17, i32 4, metadata !51, null}
!51 = metadata !{i32 786443, metadata !52, i32 15, i32 27, metadata !27, i32 4} ; [ DW_TAG_lexical_block ]
!52 = metadata !{i32 786443, metadata !53, i32 15, i32 3, metadata !27, i32 3} ; [ DW_TAG_lexical_block ]
!53 = metadata !{i32 786443, metadata !46, i32 14, i32 26, metadata !27, i32 2} ; [ DW_TAG_lexical_block ]
!54 = metadata !{i32 20, i32 5, metadata !55, null}
!55 = metadata !{i32 786443, metadata !51, i32 19, i32 26, metadata !27, i32 5} ; [ DW_TAG_lexical_block ]
!56 = metadata !{i32 15, i32 7, metadata !52, null}
!57 = metadata !{i32 15, i32 23, metadata !52, null}
!58 = metadata !{i32 16, i32 4, metadata !51, null}
!59 = metadata !{i32 786688, metadata !47, metadata !"x", metadata !27, i32 13, metadata !30, i32 0, i32 0} ; [ DW_TAG_auto_variable ]
!60 = metadata !{i32 24, i32 2, metadata !47, null}
