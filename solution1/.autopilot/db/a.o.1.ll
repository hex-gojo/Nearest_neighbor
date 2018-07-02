; ModuleID = 'D:/gojo/workspace/V_HLS/Vivado_HLS_2017-4/Nearest_neighbor/solution1/.autopilot/db/a.g.1.bc'
target datalayout = "e-p:64:64:64-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v64:64:64-v128:128:128-a0:0:64-s0:64:64-f80:128:128-n8:16:32:64-S128"
target triple = "x86_64-w64-mingw32"

@nearest_neighbor_axim.str = internal unnamed_addr constant [22 x i8] c"nearest_neighbor_axim\00" ; [#uses=1 type=[22 x i8]*]

; [#uses=0]
define i32 @nearest_neighbor_axim(i32* %cam_fb, i32* %nn_fb) nounwind uwtable {
  call void (...)* @_ssdm_op_SpecBitsMap(i32 0) nounwind, !map !22
  call void (...)* @_ssdm_op_SpecTopModule([22 x i8]* @nearest_neighbor_axim.str) nounwind
  call void @llvm.dbg.value(metadata !{i32* %cam_fb}, i64 0, metadata !28), !dbg !29 ; [debug line = 12:49] [debug variable = cam_fb]
  call void @llvm.dbg.value(metadata !{i32* %nn_fb}, i64 0, metadata !30), !dbg !31 ; [debug line = 12:88] [debug variable = nn_fb]
  call void (...)* @_ssdm_SpecArrayDimSize(i32* %cam_fb, i32 4096), !dbg !32 ; [debug line = 12:106]
  call void (...)* @_ssdm_SpecArrayDimSize(i32* %nn_fb, i32 16384), !dbg !34 ; [debug line = 12:145]
  br label %1, !dbg !35                           ; [debug line = 14:6]

; <label>:1                                       ; preds = %4, %0
  %y = phi i32 [ 0, %0 ], [ %y.1, %4 ]            ; [#uses=5 type=i32]
  %exitcond1 = icmp eq i32 %y, 128, !dbg !35      ; [#uses=1 type=i1] [debug line = 14:6]
  br i1 %exitcond1, label %5, label %.preheader.preheader, !dbg !35 ; [debug line = 14:6]

.preheader.preheader:                             ; preds = %1
  %yp = sdiv i32 %y, 2, !dbg !37                  ; [#uses=1 type=i32] [debug line = 17:4]
  %tmp = icmp slt i32 %y, 128, !dbg !41           ; [#uses=1 type=i1] [debug line = 19:4]
  %tmp.1 = mul i32 %yp, 64, !dbg !42              ; [#uses=1 type=i32] [debug line = 20:5]
  %tmp.2 = mul i32 %y, 128, !dbg !42              ; [#uses=1 type=i32] [debug line = 20:5]
  br label %.preheader, !dbg !44                  ; [debug line = 15:7]

.preheader:                                       ; preds = %._crit_edge, %.preheader.preheader
  %x = phi i32 [ %x.1, %._crit_edge ], [ 0, %.preheader.preheader ] ; [#uses=5 type=i32]
  %exitcond = icmp eq i32 %x, 128, !dbg !44       ; [#uses=1 type=i1] [debug line = 15:7]
  br i1 %exitcond, label %4, label %2, !dbg !44   ; [debug line = 15:7]

; <label>:2                                       ; preds = %.preheader
  %xp = sdiv i32 %x, 2, !dbg !45                  ; [#uses=1 type=i32] [debug line = 16:4]
  call void @llvm.dbg.value(metadata !{i32 %xp}, i64 0, metadata !46), !dbg !45 ; [debug line = 16:4] [debug variable = xp]
  call void @llvm.dbg.value(metadata !{i32 %yp}, i64 0, metadata !47), !dbg !37 ; [debug line = 17:4] [debug variable = yp]
  %tmp.4 = icmp slt i32 %x, 128, !dbg !41         ; [#uses=1 type=i1] [debug line = 19:4]
  %or.cond = and i1 %tmp.4, %tmp, !dbg !41        ; [#uses=1 type=i1] [debug line = 19:4]
  br i1 %or.cond, label %3, label %._crit_edge, !dbg !41 ; [debug line = 19:4]

; <label>:3                                       ; preds = %2
  %tmp.5 = add nsw i32 %xp, %tmp.1, !dbg !42      ; [#uses=1 type=i32] [debug line = 20:5]
  %tmp.6 = sext i32 %tmp.5 to i64, !dbg !42       ; [#uses=1 type=i64] [debug line = 20:5]
  %cam_fb.addr = getelementptr inbounds i32* %cam_fb, i64 %tmp.6, !dbg !42 ; [#uses=1 type=i32*] [debug line = 20:5]
  %cam_fb.load = load volatile i32* %cam_fb.addr, align 4, !dbg !42 ; [#uses=1 type=i32] [debug line = 20:5]
  %tmp.7 = add nsw i32 %x, %tmp.2, !dbg !42       ; [#uses=1 type=i32] [debug line = 20:5]
  %tmp.8 = sext i32 %tmp.7 to i64, !dbg !42       ; [#uses=1 type=i64] [debug line = 20:5]
  %nn_fb.addr = getelementptr inbounds i32* %nn_fb, i64 %tmp.8, !dbg !42 ; [#uses=1 type=i32*] [debug line = 20:5]
  store volatile i32 %cam_fb.load, i32* %nn_fb.addr, align 4, !dbg !42 ; [debug line = 20:5]
  br label %._crit_edge, !dbg !48                 ; [debug line = 21:4]

._crit_edge:                                      ; preds = %3, %2
  %x.1 = add nsw i32 %x, 1, !dbg !49              ; [#uses=1 type=i32] [debug line = 15:23]
  call void @llvm.dbg.value(metadata !{i32 %x.1}, i64 0, metadata !50), !dbg !49 ; [debug line = 15:23] [debug variable = x]
  br label %.preheader, !dbg !49                  ; [debug line = 15:23]

; <label>:4                                       ; preds = %.preheader
  %y.1 = add nsw i32 %y, 1, !dbg !51              ; [#uses=1 type=i32] [debug line = 14:22]
  call void @llvm.dbg.value(metadata !{i32 %y.1}, i64 0, metadata !52), !dbg !51 ; [debug line = 14:22] [debug variable = y]
  br label %1, !dbg !51                           ; [debug line = 14:22]

; <label>:5                                       ; preds = %1
  ret i32 0, !dbg !53                             ; [debug line = 24:2]
}

; [#uses=6]
declare void @llvm.dbg.value(metadata, i64, metadata) nounwind readnone

; [#uses=1]
declare void @_ssdm_op_SpecTopModule(...)

; [#uses=1]
declare void @_ssdm_op_SpecBitsMap(...)

; [#uses=2]
declare void @_ssdm_SpecArrayDimSize(...) nounwind

!llvm.dbg.cu = !{!0}
!opencl.kernels = !{!15}
!hls.encrypted.func = !{}

!0 = metadata !{i32 786449, i32 0, i32 1, metadata !"D:/gojo/workspace/V_HLS/Vivado_HLS_2017-4/Nearest_neighbor/solution1/.autopilot/db/nearest_neighbor.pragma.2.c", metadata !"D:\5Cgojo\5Cworkspace\5CV_HLS\5CVivado_HLS_2017-4", metadata !"clang version 3.1 ", i1 true, i1 false, metadata !"", i32 0, metadata !1, metadata !1, metadata !3, metadata !1} ; [ DW_TAG_compile_unit ]
!1 = metadata !{metadata !2}
!2 = metadata !{i32 0}
!3 = metadata !{metadata !4}
!4 = metadata !{metadata !5}
!5 = metadata !{i32 786478, i32 0, metadata !6, metadata !"nearest_neighbor_axim", metadata !"nearest_neighbor_axim", metadata !"", metadata !6, i32 12, metadata !7, i1 false, i1 true, i32 0, i32 0, null, i32 256, i1 false, i32 (i32*, i32*)* @nearest_neighbor_axim, null, null, metadata !13, i32 12} ; [ DW_TAG_subprogram ]
!6 = metadata !{i32 786473, metadata !"Nearest_neighbor/nearest_neighbor.c", metadata !"D:\5Cgojo\5Cworkspace\5CV_HLS\5CVivado_HLS_2017-4", null} ; [ DW_TAG_file_type ]
!7 = metadata !{i32 786453, i32 0, metadata !"", i32 0, i32 0, i64 0, i64 0, i64 0, i32 0, null, metadata !8, i32 0, i32 0} ; [ DW_TAG_subroutine_type ]
!8 = metadata !{metadata !9, metadata !10, metadata !10}
!9 = metadata !{i32 786468, null, metadata !"int", null, i32 0, i64 32, i64 32, i64 0, i32 0, i32 5} ; [ DW_TAG_base_type ]
!10 = metadata !{i32 786447, null, metadata !"", null, i32 0, i64 64, i64 64, i64 0, i32 0, metadata !11} ; [ DW_TAG_pointer_type ]
!11 = metadata !{i32 786485, null, metadata !"", null, i32 0, i64 0, i64 0, i64 0, i32 0, metadata !12} ; [ DW_TAG_volatile_type ]
!12 = metadata !{i32 786468, null, metadata !"unsigned int", null, i32 0, i64 32, i64 32, i64 0, i32 0, i32 7} ; [ DW_TAG_base_type ]
!13 = metadata !{metadata !14}
!14 = metadata !{i32 786468}                      ; [ DW_TAG_base_type ]
!15 = metadata !{i32 (i32*, i32*)* @nearest_neighbor_axim, metadata !16, metadata !17, metadata !18, metadata !19, metadata !20, metadata !21}
!16 = metadata !{metadata !"kernel_arg_addr_space", i32 1, i32 1}
!17 = metadata !{metadata !"kernel_arg_access_qual", metadata !"none", metadata !"none"}
!18 = metadata !{metadata !"kernel_arg_type", metadata !"uint*", metadata !"uint*"}
!19 = metadata !{metadata !"kernel_arg_type_qual", metadata !"volatile", metadata !"volatile"}
!20 = metadata !{metadata !"kernel_arg_name", metadata !"cam_fb", metadata !"nn_fb"}
!21 = metadata !{metadata !"reqd_work_group_size", i32 1, i32 1, i32 1}
!22 = metadata !{metadata !23}
!23 = metadata !{i32 0, i32 31, metadata !24}
!24 = metadata !{metadata !25}
!25 = metadata !{metadata !"return", metadata !26, metadata !"int", i32 0, i32 31}
!26 = metadata !{metadata !27}
!27 = metadata !{i32 0, i32 1, i32 0}
!28 = metadata !{i32 786689, metadata !5, metadata !"cam_fb", metadata !6, i32 16777228, metadata !10, i32 0, i32 0} ; [ DW_TAG_arg_variable ]
!29 = metadata !{i32 12, i32 49, metadata !5, null}
!30 = metadata !{i32 786689, metadata !5, metadata !"nn_fb", metadata !6, i32 33554444, metadata !10, i32 0, i32 0} ; [ DW_TAG_arg_variable ]
!31 = metadata !{i32 12, i32 88, metadata !5, null}
!32 = metadata !{i32 12, i32 106, metadata !33, null}
!33 = metadata !{i32 786443, metadata !5, i32 12, i32 105, metadata !6, i32 0} ; [ DW_TAG_lexical_block ]
!34 = metadata !{i32 12, i32 145, metadata !33, null}
!35 = metadata !{i32 14, i32 6, metadata !36, null}
!36 = metadata !{i32 786443, metadata !33, i32 14, i32 2, metadata !6, i32 1} ; [ DW_TAG_lexical_block ]
!37 = metadata !{i32 17, i32 4, metadata !38, null}
!38 = metadata !{i32 786443, metadata !39, i32 15, i32 27, metadata !6, i32 4} ; [ DW_TAG_lexical_block ]
!39 = metadata !{i32 786443, metadata !40, i32 15, i32 3, metadata !6, i32 3} ; [ DW_TAG_lexical_block ]
!40 = metadata !{i32 786443, metadata !36, i32 14, i32 26, metadata !6, i32 2} ; [ DW_TAG_lexical_block ]
!41 = metadata !{i32 19, i32 4, metadata !38, null}
!42 = metadata !{i32 20, i32 5, metadata !43, null}
!43 = metadata !{i32 786443, metadata !38, i32 19, i32 26, metadata !6, i32 5} ; [ DW_TAG_lexical_block ]
!44 = metadata !{i32 15, i32 7, metadata !39, null}
!45 = metadata !{i32 16, i32 4, metadata !38, null}
!46 = metadata !{i32 786688, metadata !33, metadata !"xp", metadata !6, i32 13, metadata !9, i32 0, i32 0} ; [ DW_TAG_auto_variable ]
!47 = metadata !{i32 786688, metadata !33, metadata !"yp", metadata !6, i32 13, metadata !9, i32 0, i32 0} ; [ DW_TAG_auto_variable ]
!48 = metadata !{i32 21, i32 4, metadata !43, null}
!49 = metadata !{i32 15, i32 23, metadata !39, null}
!50 = metadata !{i32 786688, metadata !33, metadata !"x", metadata !6, i32 13, metadata !9, i32 0, i32 0} ; [ DW_TAG_auto_variable ]
!51 = metadata !{i32 14, i32 22, metadata !36, null}
!52 = metadata !{i32 786688, metadata !33, metadata !"y", metadata !6, i32 13, metadata !9, i32 0, i32 0} ; [ DW_TAG_auto_variable ]
!53 = metadata !{i32 24, i32 2, metadata !33, null}
