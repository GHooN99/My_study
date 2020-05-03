%%plot 
gasprices = readtable("../데이터/gasprices.xlsx", "Range", "A5:K24");

Year = gasprices.Year;

Au = gasprices.Australia;
Ge = gasprices.Germany;
Me = gasprices.Mexico;
US = gasprices.USA;

avg = mean(Au(~isnan(Au))); %nan 이 아닌것들의 평균 
Au(isnan(Au)) = avg;

figure("Name","gasprices");

hold on ;   % 한곳에 겹쳐서 동시에 
plot(Year,Au,'r--o')
plot(Year,Ge,'g--o')
% hold off  % 따로
plot(Year,Me,'b--o')
title("Annual gas prices","Color","b")
xlabel("Year")
ylabel("Price")
legend("Au","Ge","ME")

xlim([1992,2006]); % 범위 설정 

figure("Name","gasprices subplot");
subplot(2,2,1)
plot(Year,Au,'r--o')
title("AU")
subplot(2,2,2)
plot(Year,Ge,'g--o')
title("GE")
subplot(2,2,3)
 plot(Year,Me,'b--o')
 title("ME")
 subplot(2,2,4)
 plot(Year,US,'b--o')
 title("US")
 % gird 로 나타낼때 y_scale 에 주의 해야함 
 % ylim([1,8]) 로 맞춤


[MaxPrice_USA,index] = max(US);























