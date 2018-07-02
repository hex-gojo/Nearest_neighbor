; ModuleID = 'D:/gojo/workspace/V_HLS/Vivado_HLS_2017-4/Nearest_neighbor/solution1/.autopilot/db/a.o.bc'
target datalayout = "e-p:64:64:64-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v64:64:64-v128:128:128-a0:0:64-s0:64:64-f80:128:128-n8:16:32:64-S128"
target triple = "x86_64-w64-mingw32"

; [#uses=0]
define i32 @nearest_neighbor_axim(i32* %cam_fb, i32* %nn_fb) nounwind uwtable {
  %1 = alloca i32*, align 8                       ; [#uses=3 type=i32**]
  %2 = alloca i32*, align 8                       ; [#uses=3 type=i32**]
  %y = alloca i32, align 4                        ; [#uses=6 type=i32*]
  %x = alloca i32, align 4                        ; [#uses=6 type=i32*]
  %xp = alloca i32, align 4                       ; [#uses=3 type=i32*]
  %yp = alloca i32, align 4                       ; [#uses=3 type=i32*]
  store i32* %cam_fb, i32** %1, align 8
  call void @llvm.dbg.declare(metadata !{i32** %1}, metadata !22), !dbg !23 ; [debug line = 12:49] [debug variable = cam_fb]
  store i32* %nn_fb, i32** %2, align 8
  call void @llvm.dbg.declare(metadata !{i32** %2}, metadata !24), !dbg !25 ; [debug line = 12:88] [debug variable = nn_fb]
  %3 = load i32** %1, align 8, !dbg !26           ; [#uses=1 type=i32*] [debug line = 12:106]
  call void bitcast (void (...)* @_ssdm_SpecArrayDimSize to void (i32*, i32)*)(i32* %3, i32 4096) nounwind, !dbg !26 ; [debug line = 12:106]
  %4 = load i32** %2, align 8, !dbg !28           ; [#uses=1 type=i32*] [debug line = 12:145]
  call void bitcast (void (...)* @_ssdm_SpecArrayDimSize to void (i32*, i32)*)(i32* %4, i32 16384) nounwind, !dbg !28 ; [debug line = 12:145]
  call void @llvm.dbg.declare(metadata !{i32* %y}, metadata !29), !dbg !30 ; [debug line = 13:6] [debug variable = y]
  call void @llvm.dbg.declare(metadata !{i32* %x}, metadata !31), !dbg !32 ; [debug line = 13:9] [debug variable = x]
  call void @llvm.dbg.declare(metadata !{i32* %xp}, metadata !33), !dbg !34 ; [debug line = 13:12] [debug variable = xp]
  call void @llvm.dbg.declare(metadata !{i32* %yp}, metadata !35), !dbg !36 ; [debug line = 13:16] [debug variable = yp]
  store i32 0, i32* %y, align 4, !dbg !37         ; [debug line = 14:6]
  br label %5, !dbg !37                           ; [debug line = 14:6]

; <label>:5                                       ; preds = %43, %0
  %6 = load i32* %y, align 4, !dbg !37            ; [#uses=1 type=i32] [debug line = 14:6]
  %7 = icmp slt i32 %6, 128, !dbg !37             ; [#uses=1 type=i1] [debug line = 14:6]
  br i1 %7, label %8, label %46, !dbg !37         ; [debug line = 14:6]

; <label>:8                                       ; preds = %5
  store i32 0, i32* %x, align 4, !dbg !39         ; [debug line = 15:7]
  br label %9, !dbg !39                           ; [debug line = 15:7]

; <label>:9                                       ; preds = %39, %8
  %10 = load i32* %x, align 4, !dbg !39           ; [#uses=1 type=i32] [debug line = 15:7]
  %11 = icmp slt i32 %10, 128, !dbg !39           ; [#uses=1 type=i1] [debug line = 15:7]
  br i1 %11, label %12, label %42, !dbg !39       ; [debug line = 15:7]

; <label>:12                                      ; preds = %9
  %13 = load i32* %x, align 4, !dbg !42           ; [#uses=1 type=i32] [debug line = 16:4]
  %14 = sdiv i32 %13, 2, !dbg !42                 ; [#uses=1 type=i32] [debug line = 16:4]
  store i32 %14, i32* %xp, align 4, !dbg !42      ; [debug line = 16:4]
  %15 = load i32* %y, align 4, !dbg !44           ; [#uses=1 type=i32] [debug line = 17:4]
  %16 = sdiv i32 %15, 2, !dbg !44                 ; [#uses=1 type=i32] [debug line = 17:4]
  store i32 %16, i32* %yp, align 4, !dbg !44      ; [debug line = 17:4]
  %17 = load i32* %xp, align 4, !dbg !45          ; [#uses=1 type=i32] [debug line = 19:4]
  %18 = icmp slt i32 %17, 64, !dbg !45            ; [#uses=1 type=i1] [debug line = 19:4]
  br i1 %18, label %19, label %38, !dbg !45       ; [debug line = 19:4]

; <label>:19                                      ; preds = %12
  %20 = load i32* %yp, align 4, !dbg !45          ; [#uses=1 type=i32] [debug line = 19:4]
  %21 = icmp slt i32 %20, 64, !dbg !45            ; [#uses=1 type=i1] [debug line = 19:4]
  br i1 %21, label %22, label %38, !dbg !45       ; [debug line = 19:4]

; <label>:22                                      ; preds = %19
  %23 = load i32* %yp, align 4, !dbg !46          ; [#uses=1 type=i32] [debug line = 20:5]
  %24 = mul nsw i32 %23, 64, !dbg !46             ; [#uses=1 type=i32] [debug line = 20:5]
  %25 = load i32* %xp, align 4, !dbg !46          ; [#uses=1 type=i32] [debug line = 20:5]
  %26 = add nsw i32 %24, %25, !dbg !46            ; [#uses=1 type=i32] [debug line = 20:5]
  %27 = sext i32 %26 to i64, !dbg !46             ; [#uses=1 type=i64] [debug line = 20:5]
  %28 = load i32** %1, align 8, !dbg !46          ; [#uses=1 type=i32*] [debug line = 20:5]
  %29 = getelementptr inbounds i32* %28, i64 %27, !dbg !46 ; [#uses=1 type=i32*] [debug line = 20:5]
  %30 = load volatile i32* %29, align 4, !dbg !46 ; [#uses=1 type=i32] [debug line = 20:5]
  %31 = load i32* %y, align 4, !dbg !46           ; [#uses=1 type=i32] [debug line = 20:5]
  %32 = mul nsw i32 %31, 128, !dbg !46            ; [#uses=1 type=i32] [debug line = 20:5]
  %33 = load i32* %x, align 4, !dbg !46           ; [#uses=1 type=i32] [debug line = 20:5]
  %34 = add nsw i32 %32, %33, !dbg !46            ; [#uses=1 type=i32] [debug line = 20:5]
  %35 = sext i32 %34 to i64, !dbg !46             ; [#uses=1 type=i64] [debug line = 20:5]
  %36 = load i32** %2, align 8, !dbg !46          ; [#uses=1 type=i32*] [debug line = 20:5]
  %37 = getelementptr inbounds i32* %36, i64 %35, !dbg !46 ; [#uses=1 type=i32*] [debug line = 20:5]
  store volatile i32 %30, i32* %37, align 4, !dbg !46 ; [debug line = 20:5]
  br label %38, !dbg !48                          ; [debug line = 21:4]

; <label>:38                                      ; preds = %22, %19, %12
  br label %39, !dbg !49                          ; [debug line = 22:3]

; <label>:39                                      ; preds = %38
  %40 = load i32* %x, align 4, !dbg !50           ; [#uses=1 type=i32] [debug line = 15:23]
  %41 = add nsw i32 %40, 1, !dbg !50              ; [#uses=1 type=i32] [debug line = 15:23]
  store i32 %41, i32* %x, align 4, !dbg !50       ; [debug line = 15:23]
  br label %9, !dbg !50                           ; [debug line = 15:23]

; <label>:42                                      ; preds = %9
  br label %43, !dbg !51                          ; [debug line = 23:2]

; <label>:43                                      ; preds = %42
  %44 = load i32* %y, align 4, !dbg !52           ; [#uses=1 type=i32] [debug line = 14:22]
  %45 = add nsw i32 %44, 1, !dbg !52              ; [#uses=1 type=i32] [debug line = 14:22]
  store i32 %45, i32* %y, align 4, !dbg !52       ; [debug line = 14:22]
  br label %5, !dbg !52                           ; [debug line = 14:22]

; <label>:46                                      ; preds = %5
  ret i32 0, !dbg !53                             ; [debug line = 24:2]
}

; [#uses=6]
declare void @llvm.dbg.declare(metadata, metadata) nounwind readnone

; [#uses=1]
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
!22 = metadata !{i32 786689, metadata !5, metadata !"cam_fb", metadata !6, i32 16777228, metadata !10, i32 0, i32 0} ; [ DW_TAG_arg_variable ]
!23 = metadata !{i32 12, i32 49, metadata !5, null}
!24 = metadata !{i32 786689, metadata !5, metadata !"nn_fb", metadata !6, i32 33554444, metadata !10, i32 0, i32 0} ; [ DW_TAG_arg_variable ]
!25 = metadata !{i32 12, i32 88, metadata !5, null}
!26 = metadata !{i32 12, i32 106, metadata !27, null}
!27 = metadata !{i32 786443, metadata !5, i32 12, i32 105, metadata !6, i32 0} ; [ DW_TAG_lexical_block ]
!28 = metadata !{i32 12, i32 145, metadata !27, null}
!29 = metadata !{i32 786688, metadata !27, metadata !"y", metadata !6, i32 13, metadata !9, i32 0, i32 0} ; [ DW_TAG_auto_variable ]
!30 = metadata !{i32 13, i32 6, metadata !27, null}
!31 = metadata !{i32 786688, metadata !27, metadata !"x", metadata !6, i32 13, metadata !9, i32 0, i32 0} ; [ DW_TAG_auto_variable ]
!32 = metadata !{i32 13, i32 9, metadata !27, null}
!33 = metadata !{i32 786688, metadata !27, metadata !"xp", metadata !6, i32 13, metadata !9, i32 0, i32 0} ; [ DW_TAG_auto_variable ]
!34 = metadata !{i32 13, i32 12, metadata !27, null}
!35 = metadata !{i32 786688, metadata !27, metadata !"yp", metadata !6, i32 13, metadata !9, i32 0, i32 0} ; [ DW_TAG_auto_variable ]
!36 = metadata !{i32 13, i32 16, metadata !27, null}
!37 = metadata !{i32 14, i32 6, metadata !38, null}
!38 = metadata !{i32 786443, metadata !27, i32 14, i32 2, metadata !6, i32 1} ; [ DW_TAG_lexical_block ]
!39 = metadata !{i32 15, i32 7, metadata !40, null}
!40 = metadata !{i32 786443, metadata !41, i32 15, i32 3, metadata !6, i32 3} ; [ DW_TAG_lexical_block ]
!41 = metadata !{i32 786443, metadata !38, i32 14, i32 26, metadata !6, i32 2} ; [ DW_TAG_lexical_block ]
!42 = metadata !{i32 16, i32 4, metadata !43, null}
!43 = metadata !{i32 786443, metadata !40, i32 15, i32 27, metadata !6, i32 4} ; [ DW_TAG_lexical_block ]
!44 = metadata !{i32 17, i32 4, metadata !43, null}
!45 = metadata !{i32 19, i32 4, metadata !43, null}
!46 = metadata !{i32 20, i32 5, metadata !47, null}
!47 = metadata !{i32 786443, metadata !43, i32 19, i32 26, metadata !6, i32 5} ; [ DW_TAG_lexical_block ]
!48 = metadata !{i32 21, i32 4, metadata !47, null}
!49 = metadata !{i32 22, i32 3, metadata !43, null}
!50 = metadata !{i32 15, i32 23, metadata !40, null}
!51 = metadata !{i32 23, i32 2, metadata !41, null}
!52 = metadata !{i32 14, i32 22, metadata !38, null}
!53 = metadata !{i32 24, i32 2, metadata !27, null}
