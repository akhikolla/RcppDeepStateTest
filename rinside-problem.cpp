#include <RInside.h>
#include <DeepState.hpp>
TEST(deepstate_test,rinside_test){
    RInside R;
    R["txt"] = "Hello, world!\n";
    R.parseEvalQ("cat(txt)");
}
