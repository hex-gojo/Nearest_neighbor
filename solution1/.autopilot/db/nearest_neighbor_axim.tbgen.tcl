set C_TypeInfoList {{ 
"nearest_neighbor_axim" : [[], {"return": [[], {"scalar": "int"}] }, [{"ExternC" : 0}], [ {"cam_fb": [[], {"array": [ {"scalar": "unsigned int"}, [4096]]}] }, {"nn_fb": [[], {"array": [ {"scalar": "unsigned int"}, [16384]]}] }],[],""]
}}
set moduleName nearest_neighbor_axim
set isCombinational 0
set isDatapathOnly 0
set isPipelined 0
set pipeline_type none
set FunctionProtocol ap_ctrl_hs
set isOneStateSeq 0
set ProfileFlag 0
set StallSigGenFlag 0
set C_modelName {nearest_neighbor_axim}
set C_modelType { int 32 }
set C_modelArgList {
	{ cam_fb int 32 regular {array 4096 { 1 3 } 1 1 }  }
	{ nn_fb int 32 regular {array 16384 { 0 3 } 0 1 }  }
}
set C_modelArgMapList {[ 
	{ "Name" : "cam_fb", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "cam_fb","cData": "unsigned int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 4095,"step" : 1}]}]}]} , 
 	{ "Name" : "nn_fb", "interface" : "memory", "bitwidth" : 32, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "nn_fb","cData": "unsigned int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 16383,"step" : 1}]}]}]} , 
 	{ "Name" : "ap_return", "interface" : "wire", "bitwidth" : 32,"bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "return","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 1,"step" : 0}]}]}]} ]}
# RTL Port declarations: 
set portNum 14
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ cam_fb_address0 sc_out sc_lv 12 signal 0 } 
	{ cam_fb_ce0 sc_out sc_logic 1 signal 0 } 
	{ cam_fb_q0 sc_in sc_lv 32 signal 0 } 
	{ nn_fb_address0 sc_out sc_lv 14 signal 1 } 
	{ nn_fb_ce0 sc_out sc_logic 1 signal 1 } 
	{ nn_fb_we0 sc_out sc_logic 1 signal 1 } 
	{ nn_fb_d0 sc_out sc_lv 32 signal 1 } 
	{ ap_return sc_out sc_lv 32 signal -1 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "cam_fb_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":12, "type": "signal", "bundle":{"name": "cam_fb", "role": "address0" }} , 
 	{ "name": "cam_fb_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "cam_fb", "role": "ce0" }} , 
 	{ "name": "cam_fb_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "cam_fb", "role": "q0" }} , 
 	{ "name": "nn_fb_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":14, "type": "signal", "bundle":{"name": "nn_fb", "role": "address0" }} , 
 	{ "name": "nn_fb_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "nn_fb", "role": "ce0" }} , 
 	{ "name": "nn_fb_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "nn_fb", "role": "we0" }} , 
 	{ "name": "nn_fb_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "nn_fb", "role": "d0" }} , 
 	{ "name": "ap_return", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "ap_return", "role": "default" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "",
		"CDFG" : "nearest_neighbor_axim",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"FunctionPipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"VariableLatency" : "1",
		"Port" : [
			{"Name" : "cam_fb", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "nn_fb", "Type" : "Memory", "Direction" : "O"}]}]}


set ArgLastReadFirstWriteLatency {
	nearest_neighbor_axim {
		cam_fb {Type I LastRead 2 FirstWrite -1}
		nn_fb {Type O LastRead -1 FirstWrite 3}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "33025", "Max" : "33025"}
	, {"Name" : "Interval", "Min" : "33026", "Max" : "33026"}
]}

set PipelineEnableSignalInfo {[
]}

set Spec2ImplPortList { 
	cam_fb { ap_memory {  { cam_fb_address0 mem_address 1 12 }  { cam_fb_ce0 mem_ce 1 1 }  { cam_fb_q0 mem_dout 0 32 } } }
	nn_fb { ap_memory {  { nn_fb_address0 mem_address 1 14 }  { nn_fb_ce0 mem_ce 1 1 }  { nn_fb_we0 mem_we 1 1 }  { nn_fb_d0 mem_din 1 32 } } }
}

set busDeadlockParameterList { 
}

# RTL port scheduling information:
set fifoSchedulingInfoList { 
}

# RTL bus port read request latency information:
set busReadReqLatencyList { 
}

# RTL bus port write response latency information:
set busWriteResLatencyList { 
}

# RTL array port load latency information:
set memoryLoadLatencyList { 
}
