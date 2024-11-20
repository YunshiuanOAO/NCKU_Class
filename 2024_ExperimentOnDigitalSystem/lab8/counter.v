module counter(
    input clock,
    input reset,       
    input Up_Down,     
    output [6:0] out   
);
wire clock_div;        
wire [3:0] count;      

FrequencyDivider u_FreqDiv (
    .clk(clock),
    .reset(reset),
    .clk_div(clock_div)
);

Counter u_counter (
    .clk(clock_div),
    .reset(reset),
    .Up_Down(Up_Down),
    .count(count)
);

SevenDisplay u_display (
    .in(count),
    .out(out)
);

endmodule

module FrequencyDivider(
    input clk,          
    input reset,        
    output reg clk_div 
);

reg [31:0] clk_counter;
always @(posedge clk or negedge reset) begin
    if (!reset) begin
        clk_counter <= 32'd0;
        clk_div <= 1'b0;
    end else begin
        if (clk_counter == 32'd25000000) begin // 經過一秒
            clk_counter <= 32'd0;
            clk_div <= ~clk_div; 
        end else begin
            clk_counter <= clk_counter + 32'd1;
        end
    end
end

endmodule

module Counter(
    input clk,          
    input reset,        
    input Up_Down,      
    output reg [3:0] count 
);

always @(posedge clk or negedge reset) begin
    if (!reset) begin
        count <= 4'd0;
    end else begin
        if (Up_Down) begin
            count <= count + 4'd1;
        end else begin
            count <= count - 4'd1;
        end
    end
end

endmodule

module SevenDisplay(
    input [3:0] in,    
    output reg [6:0] out 
);

always @(*) begin
    case (in)
        4'h0: out = 7'b1000000;
        4'h1: out = 7'b1111001;
        4'h2: out = 7'b0100100;
        4'h3: out = 7'b0110000;
        4'h4: out = 7'b0011001;
        4'h5: out = 7'b0010010;
        4'h6: out = 7'b0000010;
        4'h7: out = 7'b1111000;
        4'h8: out = 7'b0000000;
        4'h9: out = 7'b0010000;
        4'hA: out = 7'b0001000;
        4'hB: out = 7'b0000011;
        4'hC: out = 7'b1000110;
        4'hD: out = 7'b0100001;
        4'hE: out = 7'b0000110;
        4'hF: out = 7'b0001110;
        default: out = 7'b1111111;
    endcase
end

endmodule
