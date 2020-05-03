gasprices = readtable("../데이터/gasprices.xlsx", "Range", "A5:K24");

Year = gasprices.Year;

Au = gasprices.Australia;
Ge = gasprices.Germany;
Me = gasprices.Mexico;
US = gasprices.USA;

avg = mean(Au(~isnan(Au))); %nan 이 아닌것들의 평균 
Au(isnan(Au)) = avg;

gasprices.Australia = Au;

%%
country = gasprices.Properties.VariableNames(2:end)

% input 

% mycountry = inputdlg('enter a country');

mycountry = input('enter a country','s');
idx =strcmp(mycountry,country)
select = country{idx}

idx1 = listdlg('PromptString','Select','SelectionMode','single','ListString',country)

%% For While 

x = 10;
minVal = 2;
maxVal = 7;

if x>=minVal && x<=maxVal
disp("1");
elseif(x>maxVal)
disp("2");
else
disp("3");    
end

for i=1:10:100
disp(i)
end



