CarSpecs = readtable("../데이터/CarSpecs.xls"); %모두 가져옴
CarSpecs1 = xlsread("../데이터/CarSpecs.xls"); %숫자만 가져와서 자료 손상 

figure("Name","Power EngineSize")
scatter(CarSpecs.EngineSize,CarSpecs.Power);
xlabel('EngineSize');
ylabel('Power');
title("Power vs EngineSize");

PtW = CarSpecs.Power ./ CarSpecs.Weight;  %PtW 열 추가 

CarSpecs.PtW = PtW

[PtW_Max,idx] = max(CarSpecs.PtW)

%% Cell Array

CarSpecs.Model{1}    %문자열 뽑기  ()과는 다름

CarSpecs.Make{idx}

[byPtw,index] = sortrows(CarSpecs,'PtW','descend'); % 원본 인덱스도 반환

%% Week 5 

CarSpecs.EngineSize(1)
byPtW1to5 = byPtw(1:5 , [1,2,end]);       % 1행~ 5행까지 1,2,end 열 1,5만 출력하려면 [1,5]
byPtW1to5_cellArray = byPtw(1:5,{'Make','Model','PtW'})         % 변수명(cell array)을 통해 불러옴

        
