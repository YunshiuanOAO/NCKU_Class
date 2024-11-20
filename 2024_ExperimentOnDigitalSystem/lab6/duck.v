module duck (a, out, valid);

input [7:0] a;
output [2:0] out;
output valid;
reg [2:0] out_reg;
reg valid_reg;
assign out = out_reg;
assign valid = valid_reg;

always@(*) begin
    case(a)
        8'b00000001: begin
            out_reg = 3'b000;
            valid_reg = 1'b1;
        end
        8'b00000010: begin
            out_reg = 3'b001;
            valid_reg = 1'b1;
        end
        8'b00000100: begin
            out_reg = 3'b010;
            valid_reg = 1'b1;
        end
        8'b00001000: begin
            out_reg = 3'b011;
            valid_reg = 1'b1;
        end
        8'b00010000: begin
            out_reg = 3'b100;
            valid_reg = 1'b1;
        end
        8'b00100000: begin
            out_reg = 3'b101;
            valid_reg = 1'b1;
        end
        8'b01000000: begin
            out_reg = 3'b110;
            valid_reg = 1'b1;
        end
        8'b10000000: begin
            out_reg = 3'b111;
            valid_reg = 1'b1;
        end
        default: begin
            out_reg = 3'b000;
            valid_reg = 1'b0;
        end
    endcase
end

endmodule
