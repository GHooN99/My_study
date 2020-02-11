#gradient_descent_without_lib

def costFunc(x_data,y_data,W,b):
    cost = 0
    for i in range(len(x_data)):
        hypothesis = W*x_data[i] + b
        cost += (hypothesis-y_data[i]) ** 2
        
    return cost/len(x_data)

def gradient(x_data,y_data,W,b):
    w_cost = 0
    b_cost = 0
    
    for i in range(len(x_data)):
        hypothesis = W*x_data[i] + b
        w_cost += 2*(hypothesis-y_data[i]) *x_data[i]
        
    for i in range(len(x_data)):
        hypothesis = W*x_data[i] + b
        b_cost += 2*(hypothesis-y_data[i])
        
    return w_cost/len(x_data), b_cost/len(x_data)
    

x_data = list(range(1,11))
y_data = list(range(1,21,2))

W = 30.0
b = 14.0
rate = 0.001

for i in range(50000):
    
    w_grad, b_grad =gradient(x_data,y_data,W,b)
    
    W-= rate * w_grad
    b-= rate * b_grad
    cost = costFunc(x_data,y_data,W,b)
    
    if i%1000==0:
        print("%d || cost : %f || W : %f || b :%f ||"%(i,cost,W,b))


print("x = 10 -> %d"%(W*10+b))





