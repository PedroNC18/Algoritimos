module teclado(clk, linha, coluna, teste);

input clk;
input [3:0]linha;

output reg [3:0]coluna;
output reg teste;

reg [1:0]state;

reg N_0,N_1,N_2,N_3,N_4,N_5,N_6,N_7,N_8,N_9,N_esp;

wire N_0i,N_1i,N_2i,N_3i,N_4i,N_5i,N_6i,N_7i,N_8i,N_9i,N_espi;

reg N_0d,N_1d,N_2d,N_3d,N_4d,N_5d,N_6d,N_7d,N_8d,N_9d,N_espd;

wire N_0f,N_1f,N_2f,N_3f,N_4f,N_5f,N_6f,N_7f,N_8f,N_9f,N_espf;

assign N_0i = N_0;
assign N_1i = N_1;
assign N_2i = N_2;
assign N_3i = N_3;
assign N_4i = N_4;
assign N_5i = N_5;
assign N_6i = N_6;
assign N_7i = N_7;
assign N_8i = N_8;
assign N_9i = N_9;
assign N_espi = N_esp;

assign N_0f = N_0d;
assign N_1f = N_1d;
assign N_2f = N_2d;
assign N_3f = N_3d;
assign N_4f = N_4d;
assign N_5f = N_5d;
assign N_6f = N_6d;
assign N_7f = N_7d;
assign N_8f = N_8d;
assign N_9f = N_9d;
assign N_espf = N_espd;

deboucing A(clk,N_0i,N_0f);
deboucing B(clk,N_1i,N_1f);
deboucing C(clk,N_2i,N_2f);
deboucing D(clk,N_3i,N_3f);
deboucing E(clk,N_4i,N_4f);
deboucing F(clk,N_5i,N_5f);
deboucing G(clk,N_6i,N_6f);
deboucing H(clk,N_7i,N_7f);
deboucing I(clk,N_8i,N_8f);
deboucing J(clk,N_9i,N_9f);
deboucing K(clk,N_espi,N_espf);


parameter [1:0] coluna0=2'b00,coluna1=2'b01,
			coluna2=2'b10,deboucing=2'b11;
		  
parameter [3:0] linha0=4'b0111,linha1=4'b1011,
			linha2=4'b1101,linha3=4'b1110;

reg [18:0]cont; 

initial begin
	state<=2'b00;
	teste <= 0;
end
 
 always@(posedge clk)begin
	case(state)
	coluna0:
		begin
		coluna <= 4'b0111;
			case(linha)
			linha0:
				begin
					N_0<=0;
					N_1<=1;
					N_2<=0;
					N_3<=0;
					N_4<=0;
					N_5<=0;
					N_6<=0;
					N_7<=0;
					N_8<=0;
					N_9<=0;
					N_esp<=0;
				end
			linha1:
				begin
					N_0<=0;
					N_1<=0;
					N_2<=0;
					N_3<=0;
					N_4<=1;
					N_5<=0;
					N_6<=0;
					N_7<=0;
					N_8<=0;
					N_9<=0;
					N_esp<=0;
				end
			linha2:
				begin
					N_0<=0;
					N_1<=0;
					N_2<=0;
					N_3<=0;
					N_4<=0;
					N_5<=0;
					N_6<=0;
					N_7<=1;
					N_8<=0;
					N_9<=0;
					N_esp<=0;
				end
			linha3:
				begin
					N_0<=0;
					N_1<=0;
					N_2<=0;
					N_3<=0;
					N_4<=0;
					N_5<=0;
					N_6<=0;
					N_7<=0;
					N_8<=0;
					N_9<=0;
					N_esp<=0;
				end
			endcase
			state <= coluna1;
		end
	coluna1:
		begin
			coluna <= 4'b1011;
			case(linha)
			linha0:
				begin
					N_0<=0;
					N_1<=0;
					N_2<=1;
					N_3<=0;
					N_4<=0;
					N_5<=0;
					N_6<=0;
					N_7<=0;
					N_8<=0;
					N_9<=0;
					N_esp<=0;
				end
			linha1:
				begin
					N_0<=0;
					N_1<=0;
					N_2<=0;
					N_3<=0;
					N_4<=0;
					N_5<=1;
					N_6<=0;
					N_7<=0;
					N_8<=0;
					N_9<=0;
					N_esp<=0;
				end
			linha2:
				begin
					N_0<=0;
					N_1<=0;
					N_2<=0;
					N_3<=0;
					N_4<=0;
					N_5<=0;
					N_6<=0;
					N_7<=0;
					N_8<=1;
					N_9<=0;
					N_esp<=0;
				end
			linha3:
				begin
					N_0<=1;
					N_1<=0;
					N_2<=0;
					N_3<=0;
					N_4<=0;
					N_5<=0;
					N_6<=0;
					N_7<=0;
					N_8<=0;
					N_9<=0;
					N_esp<=0;
				end
			endcase
			state <= coluna2;
		end
	coluna2:
		begin
			coluna <= 4'b1101;
			case(linha)
			linha0:
				begin
					N_0<=1;
					N_1<=0;
					N_2<=0;
					N_3<=1;
					N_4<=0;
					N_5<=0;
					N_6<=0;
					N_7<=0;
					N_8<=0;
					N_9<=0;
					N_esp<=0;
				end
			linha1:
				begin
					N_0<=1;
					N_1<=0;
					N_2<=0;
					N_3<=0;
					N_4<=0;
					N_5<=0;
					N_6<=1;
					N_7<=0;
					N_8<=0;
					N_9<=0;
					N_esp<=0;
				end
			linha2:
				begin
					N_0<=1;
					N_1<=0;
					N_2<=0;
					N_3<=0;
					N_4<=0;
					N_5<=0;
					N_6<=0;
					N_7<=0;
					N_8<=0;
					N_9<=1;
					N_esp<=0;
				end
			linha3:
				begin
					N_0<=1;
					N_1<=0;
					N_2<=0;
					N_3<=0;
					N_4<=0;
					N_5<=0;
					N_6<=0;
					N_7<=0;
					N_8<=0;
					N_9<=0;
					N_esp<=1;
				end
			endcase
			state <= coluna0;
		end
	endcase
	if(N_0f)begin
		teste <= !teste;
	end
	else if(N_1f)begin
		teste <= !teste;
 	end
 	else if(N_2f)begin
		teste <= !teste;
 	end
 	else if(N_3f)begin
		teste <= !teste;
 	end
 	else if(N_4f)begin
		teste <= !teste;
 	end
 	else if(N_5f)begin
		teste <= !teste;
 	end
 	else if(N_6f)begin
		teste <= !teste;
 	end
 	else if(N_7f)begin
		teste <= !teste;
 	end
 	else if(N_8f)begin
		teste <= !teste;
 	end
 	else if(N_9f)begin
		teste <= !teste;
 	end
 	else if(N_espf)begin
		teste <= !teste;
 	end
 end
 endmodule 
