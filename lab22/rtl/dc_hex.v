`timescale 1ns / 1ps

module sm(
input clk_i,
input arstn_i,


input check_i,
input error_i,

output [1:0] state_o


  );
reg [1:0] state_pullreq;
reg [1:0] next_state_pullreq;

localparam PULLREQ_WAIT   =  2'd0;
localparam PULLREQ_CHECK  =  2'd1;
localparam PULLREQ_REWORK =  2'd2;
localparam PULLREQ_CLOSE  =  2'd3;

always@ (*) begin
  case (state_pullreq)
    PULLREQ_WAIT   :  if (check_i) next_state_pullreq = PULLREQ_CHECK;
                     else          next_state_pullreq = PULLREQ_WAIT;
    PULLREQ_CHECK  : if (error_i)  next_state_pullreq = PULLREQ_CHECK;
                     else          next_state_pullreq = PULLREQ_WAIT;
    PULLREQ_REWORK : next_state_pullreq = PULLREQ_WAIT;
    PULLREQ_CLOSE  : next_state_pullreq = PULLREQ_CLOSE;
  endcase
 end
                   





always@ (posedge clk_i or negedge arstn_i) begin
  if(!arstn_i)
    state_pullreq <=PULLREQ_WAIT;
  else 
    state_pullreq <=next_state_pullreq;
 end






endmodule
