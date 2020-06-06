`timescale 1ns / 1ps



module sm_key(
input clk_i,
input arstn_i,

input key0_press_i,
input key2_press_i,

output event_valid_o

);

reg [2:0] state_event_valid;
reg [2:0] next_state_event_valid;


localparam STATE_W_K0_PR_1     =  3'd0;
localparam STATE_W_K0_PR_2     =  3'd1;
localparam STATE_W_K2_PR_1     =  3'd2;
localparam STATE_W_K0_PR_3     =  3'd3;
localparam STATE_W_K0_PR_4     =  3'd4;
localparam STATE_EVENT_VALID   =  3'd5;

assign event_valid_o = ( state_event_valid == STATE_EVENT_VALID );


always@ (*) begin
  case (state_event_valid)
    STATE_W_K0_PR_1 :  if (key0_press_i) next_state_event_valid = STATE_W_K0_PR_2;
                      else             next_state_event_valid = STATE_W_K0_PR_1;
                      
    STATE_W_K0_PR_2 : if (key0_press_i)      next_state_event_valid = STATE_W_K2_PR_1;
                      else if (key2_press_i) next_state_event_valid = STATE_W_K0_PR_1;    
                      else                 next_state_event_valid = STATE_W_K0_PR_2; 
                      
    STATE_W_K2_PR_1 : if (key2_press_i)     next_state_event_valid = STATE_W_K0_PR_3;
                      else if (key0_press_i) next_state_event_valid = STATE_W_K0_PR_1;    
                      else                 next_state_event_valid = STATE_W_K2_PR_1;
                      
    STATE_W_K0_PR_3 : if (key0_press_i)      next_state_event_valid = STATE_W_K0_PR_4;
                      else if (key2_press_i) next_state_event_valid = STATE_W_K0_PR_1;    
                      else                 next_state_event_valid = STATE_W_K0_PR_3; 
    STATE_W_K0_PR_4 : if (key0_press_i)      next_state_event_valid = STATE_EVENT_VALID;
                      else if (key2_press_i) next_state_event_valid = STATE_W_K0_PR_1;    
                      else                 next_state_event_valid = STATE_W_K0_PR_4; 
    STATE_EVENT_VALID : next_state_event_valid = STATE_W_K0_PR_1;  
    default :  next_state_event_valid = STATE_W_K0_PR_1;                                                
  endcase
 end
                   


always@ (posedge clk_i or negedge arstn_i) begin
  if(!arstn_i)
    state_event_valid <=STATE_W_K0_PR_1;
  else 
    state_event_valid <=next_state_event_valid;
 end

endmodule
