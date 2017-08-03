#include <librtmvideo/video_bot.h>
#include <iostream>

namespace empty_bot {
void process_image(bot_context &context, const uint8_t *image, uint16_t width,
                   uint16_t height, uint16_t linesize) {
  std::cout << "got frame " << width << "x" << height << "\n";
}
cbor_item_t *process_command(bot_context &, cbor_item_t *) {
  std::cout << "bot is initializing, libraries are ok" << '\n';
  return nullptr;
}
}  // namespace empty_bot

int main(int argc, char *argv[]) {
  rtm_video_bot_register(bot_descriptor{640, 480, image_pixel_format::BGR,
                                        &empty_bot::process_image,
                                        &empty_bot::process_command});
  return rtm_video_bot_main(argc, argv);
}