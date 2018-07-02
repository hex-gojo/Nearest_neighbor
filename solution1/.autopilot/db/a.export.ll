; ModuleID = 'D:/gojo/workspace/V_HLS/Vivado_HLS_2017-4/Nearest_neighbor/solution1/.autopilot/db/a.o.2.bc'
target datalayout = "e-p:64:64:64-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v64:64:64-v128:128:128-a0:0:64-s0:64:64-f80:128:128-n8:16:32:64-S128"
target triple = "x86_64-w64-mingw32"

@nearest_neighbor_axi = internal unnamed_addr constant [22 x i8] c"nearest_neighbor_axim\00"

define i32 @nearest_neighbor_axim([4096 x i32]* %cam_fb, [16384 x i32]* %nn_fb) nounwind uwtable {
  call void (...)* @_ssdm_op_SpecBitsMap([4096 x i32]* %cam_fb) nounwind, !map !7
  call void (...)* @_ssdm_op_SpecBitsMap([16384 x i32]* %nn_fb) nounwind, !map !13
  call void (...)* @_ssdm_op_SpecBitsMap(i32 0) nounwind, !map !19
  call void (...)* @_ssdm_op_SpecTopModule([22 x i8]* @nearest_neighbor_axi) nounwind
  br label %.loopexit

.loopexit.loopexit:                               ; preds = %.preheader
  br label %.loopexit

.loopexit:                                        ; preds = %.loopexit.loopexit, %0
  %y = phi i8 [ 0, %0 ], [ %y_1, %.loopexit.loopexit ]
  %exitcond1 = icmp eq i8 %y, -128
  %empty = call i32 (...)* @_ssdm_op_SpecLoopTripCount(i64 128, i64 128, i64 128) nounwind
  %y_1 = add i8 %y, 1
  br i1 %exitcond1, label %1, label %.preheader.preheader

.preheader.preheader:                             ; preds = %.loopexit
  %p_lshr_f_cast = call i6 @_ssdm_op_PartSelect.i6.i8.i32.i32(i8 %y, i32 1, i32 6)
  %tmp = trunc i8 %y to i7
  %tmp_2 = call i14 @_ssdm_op_BitConcatenate.i14.i7.i7(i7 %tmp, i7 0)
  br label %.preheader

.preheader:                                       ; preds = %._crit_edge, %.preheader.preheader
  %x = phi i8 [ %x_1, %._crit_edge ], [ 0, %.preheader.preheader ]
  %x_cast3 = zext i8 %x to i14
  %exitcond = icmp eq i8 %x, -128
  %empty_4 = call i32 (...)* @_ssdm_op_SpecLoopTripCount(i64 128, i64 128, i64 128) nounwind
  %x_1 = add i8 %x, 1
  br i1 %exitcond, label %.loopexit.loopexit, label %._crit_edge

._crit_edge:                                      ; preds = %.preheader
  %p_lshr_f1_cast = call i6 @_ssdm_op_PartSelect.i6.i8.i32.i32(i8 %x, i32 1, i32 6)
  %tmp_5 = call i12 @_ssdm_op_BitConcatenate.i12.i6.i6(i6 %p_lshr_f_cast, i6 %p_lshr_f1_cast)
  %tmp_6 = zext i12 %tmp_5 to i64
  %cam_fb_addr = getelementptr [4096 x i32]* %cam_fb, i64 0, i64 %tmp_6
  %cam_fb_load = load volatile i32* %cam_fb_addr, align 4
  %tmp_7 = add i14 %tmp_2, %x_cast3
  %tmp_8 = zext i14 %tmp_7 to i64
  %nn_fb_addr = getelementptr [16384 x i32]* %nn_fb, i64 0, i64 %tmp_8
  store volatile i32 %cam_fb_load, i32* %nn_fb_addr, align 4
  br label %.preheader

; <label>:1                                       ; preds = %.loopexit
  ret i32 0
}

declare i8 @llvm.part.select.i8(i8, i32, i32) nounwind readnone

declare void @llvm.dbg.value(metadata, i64, metadata) nounwind readnone

define weak void @_ssdm_op_SpecTopModule(...) {
entry:
  ret void
}

define weak i32 @_ssdm_op_SpecLoopTripCount(...) {
entry:
  ret i32 0
}

define weak void @_ssdm_op_SpecBitsMap(...) {
entry:
  ret void
}

declare i7 @_ssdm_op_PartSelect.i7.i8.i32.i32(i8, i32, i32) nounwind readnone

define weak i6 @_ssdm_op_PartSelect.i6.i8.i32.i32(i8, i32, i32) nounwind readnone {
entry:
  %empty = call i8 @llvm.part.select.i8(i8 %0, i32 %1, i32 %2)
  %empty_5 = trunc i8 %empty to i6
  ret i6 %empty_5
}

define weak i14 @_ssdm_op_BitConcatenate.i14.i7.i7(i7, i7) nounwind readnone {
entry:
  %empty = zext i7 %0 to i14
  %empty_6 = zext i7 %1 to i14
  %empty_7 = shl i14 %empty, 7
  %empty_8 = or i14 %empty_7, %empty_6
  ret i14 %empty_8
}

define weak i12 @_ssdm_op_BitConcatenate.i12.i6.i6(i6, i6) nounwind readnone {
entry:
  %empty = zext i6 %0 to i12
  %empty_9 = zext i6 %1 to i12
  %empty_10 = shl i12 %empty, 6
  %empty_11 = or i12 %empty_10, %empty_9
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
