module pig (
    input [3:0] in,      
    output [6:0] seg   
);
    reg [6:0] result;   
    reg [6:0] seg_data;  

    always @(*) begin
        case (in)
            4'b0000, 4'b0001, 4'b0010: result = in;            
            4'b0011, 4'b0100, 4'b0101: result = in * 2 + 1;    
            4'b0110, 4'b0111, 4'b1000: result = in * 2 - 1;    
            default: result = 7'b0000000;                     
        endcase
    end

    always @(*) begin
        case (result)
            7'd0: seg_data = 7'b1000000; 
            7'd1: seg_data = 7'b1111001; 
            7'd2: seg_data = 7'b0100100;
            7'd3: seg_data = 7'b0110000; 
            7'd4: seg_data = 7'b0011001; 
            7'd5: seg_data = 7'b0010010; 
            7'd6: seg_data = 7'b0000010; 
            7'd7: seg_data = 7'b1111000; 
            7'd8: seg_data = 7'b0000000; 
            7'd9: seg_data = 7'b0010000; 
				7'd9:  seg_data = 7'b0010000; 
            7'd10: seg_data = 7'b0001000; 
            7'd11: seg_data = 7'b0000011; 
            7'd12: seg_data = 7'b1000110; 
            7'd13: seg_data = 7'b0100001; 
            7'd14: seg_data = 7'b0000110; 
            7'd15: seg_data = 7'b0001110; 
            default: seg_data = 7'b1111111;
        endcase
    end

    assign seg = seg_data;
endmodule
