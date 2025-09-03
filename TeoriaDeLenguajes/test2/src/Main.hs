module Main (main) where

suma :: Int -> Int -> Int
suma x y = x + y

inc :: Int -> Int
inc = (+ 1)

esPar :: Int -> Bool
esPar n = n `mod` 2 == 0

bmiClassify :: Double -> String
bmiClassify bmi
    | bmi < 18.5 = "Underweight"
    | bmi < 25 = "Normal weight"
    | bmi < 30 = "Overweight"
    | otherwise   = "Obesity"


main :: IO ()
main = do
    putStrLn "hello world"
    print (suma 5 6)

    print (bmiClassify 22.0)
    let lecturas1 = [20.0, 22.5, 17.8, 21.0]
    print (map bmiClassify lecturas1)
