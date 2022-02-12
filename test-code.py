import cppcode

fib = cppcode.fibonacci(10)
txt = cppcode.justify(open('LICENSE', 'r').read(), 80)

print(txt)
print('fib(10) = %d' % fib)
