CarSpecs = readtable("../������/CarSpecs.xls"); %��� ������
CarSpecs1 = xlsread("../������/CarSpecs.xls"); %���ڸ� �����ͼ� �ڷ� �ջ� 

figure("Name","Power EngineSize")
scatter(CarSpecs.EngineSize,CarSpecs.Power);
xlabel('EngineSize');
ylabel('Power');
title("Power vs EngineSize");

PtW = CarSpecs.Power ./ CarSpecs.Weight;  %PtW �� �߰� 

CarSpecs.PtW = PtW

[PtW_Max,idx] = max(CarSpecs.PtW)

%% Cell Array

CarSpecs.Model{1}    %���ڿ� �̱�  ()���� �ٸ�

CarSpecs.Make{idx}

[byPtw,index] = sortrows(CarSpecs,'PtW','descend'); % ���� �ε����� ��ȯ

%% Week 5 

CarSpecs.EngineSize(1)
byPtW1to5 = byPtw(1:5 , [1,2,end]);       % 1��~ 5����� 1,2,end �� 1,5�� ����Ϸ��� [1,5]
byPtW1to5_cellArray = byPtw(1:5,{'Make','Model','PtW'})         % ������(cell array)�� ���� �ҷ���

        
