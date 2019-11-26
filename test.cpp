// テストケース記述ファイル
#include "gtest/gtest.h" // googleTestを使用するおまじないはこれだけでOK
// テスト対象関数を呼び出せるようにするのだが
// extern "C"がないとCと解釈されない、意外とハマりがち。
extern "C" {
#include "target.h"
}

// fixtureNameはテストケース群をまとめるグループ名と考えればよい、任意の文字列
// それ以外のclass～testing::Testまではおまじないと考える
class fixtureName : public ::testing::Test {
protected:
    // fixtureNameでグループ化されたテストケースはそれぞれのテストケース実行前に
    // この関数を呼ぶ。共通の初期化処理を入れておくとテストコードがすっきりする
    virtual void SetUp(){
    }
    // SetUpと同様にテストケース実行後に呼ばれる関数。共通後始末を記述する。
    virtual void TearDown(){
    }
};

TEST_F(fixtureName, testOk1)
{
  EXPECT_EQ(1, function(0, 1));
}

TEST_F(fixtureName, testOk2)
{
  EXPECT_EQ(2, function(1, 2));
}

TEST_F(fixtureName, testOk3)
{
  EXPECT_EQ(3, function(-1, 3));
}

TEST_F(fixtureName, testOk4)
{
  EXPECT_EQ(0, function(-1, 0));
}

TEST_F(fixtureName, testOk5)
{
  EXPECT_EQ(-3, function(-3, -5));
}
